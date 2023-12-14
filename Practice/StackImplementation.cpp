#include <iostream>
using namespace std;

/*Implement stack as an abstract data type using singly linked list, use this ADT for
conversion of infix expression to postfix, prefix and evaluation of postfix, and
prefix expression. */

struct Node
{

    char data;
    Node *next;
};

class Stack
{
    Node *top;
    char x;

public:
    Stack()
    {
        top = NULL;
    }

    int isEmpty()
    {
        if (top == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(char data)
    {

        Node *temp = new Node();
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    char pop()
    {
        Node *temp = top;
        char x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }

    char topdata()
    {
        return top->data;
    }
};

int precedence(char x)
{
    if (x == '(')
    {
        return 1;
    }
    else if (x == '+' || x == '-')
    {
        return 2;
    }
    else if (x == '*' || x == '/')
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

void Infix_to_Postfix(char infix[20], char postfix[20])
{

    Stack s;
    int i, j = 0;
    char token;

    for (i = 0; infix[i] != '\0'; i++)
    {
        token = infix[i];
        if (isalnum(token))
        {
            postfix[j] = token;
            j++;
        }
        else
        {
            if (token == '(')
            {
                s.push(token);
            }
            else if (token == ')')
            {
                char x;
                while (x = s.pop() != '(')
                {
                    postfix[j] = x;
                    j++;
                }
            }
            else
            {
                while (s.isEmpty() != 1 && precedence(token) <= precedence(s.topdata()))
                {
                    postfix[j] = s.pop();
                    j++;
                }
                s.push(token);
            }
        }
    }

    while (s.isEmpty() != 1)
    {
        postfix[j] = s.pop();
        j++;
    }
    postfix[j] = '/0';
}

void reverse(char saral[20], char rev[20])
{

    int i, j = 0;
    for (i = 0; saral[i] != '\0'; i++)
    {
        j++;
    }
    j--;

    for (int i = 0; j >= 0; j--, i++)
    {
        if (saral[i] == '(')
        {
            rev[j] = ')';
        }
        if (saral[i] == ')')
        {
            rev[j] = '(';
        }
        else
        {
            rev[j] = saral[i];
        }
    }
    rev[j] = '\0';
}

void Infix_to_Prefix(char infix[20], char prefix[20])
{
    char prefix1[20];
    char infix1[20];
    reverse(infix, infix1);
    Infix_to_Postfix(infix1, prefix1);
    reverse(prefix1, prefix);
}

int Evaluate(int op1, int op2, int op)
{
    if (op == '+')
    {
        return op1 + op2;
    }
    else if (op == '-')
    {
        return op1 - op2;
    }
    else if (op == '*')
    {
        return op1 * op2;
    }
    else if (op == '/')
    {
        return op1 / op2;
    }
}

void Evaluate_Postfix(char postfix[20])
{
    cout << "Evaluating Postfix Expression" << endl;
    Stack s;
    int op1, op2;
    char op;
    int result;
    char token;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        token = postfix[i];
        if (isalnum(token))
        {
            cout << "Enter the value of " << token << " : ";
            int x;
            cin >> x;
            s.push(char(x));
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();
            int result = Evaluate(op1, op2, token);
            s.push(char(result));
        }
    }
    int answer = s.pop();
    cout << answer;
}

void Evaluate_Prefix(char prefix[20])
{

    Stack s;
    int op1, op2;
    char op;
    char token;
    int i;
    int result;
    for (i = 0; prefix[i] != '\0'; i++)
    {
    }
    i--;
    for (; i >= 0; i--)
    {
        token = prefix[i];
        if (isalnum(token))
        {
            cout << "Enter the value of " << token << " : ";
            int x;
            cin >> x;
            s.push(char(x));
        }
        else
        {
            op1 = s.pop();
            op2 = s.pop();
            int result = Evaluate(op1, op2, token);
            s.push(char(result));
        }
    }
    int answer = s.pop();
    cout << answer;
}

void Display(char x[20])
{

    for (int i = 0; x[i] != '\0'; i++)
    {
        cout << x[i] << " ";
    }
}

int main()
{
    char infix[20], prefix[20], postfix[20];

    while (true)
    {

        cout << "1 - Infix to Prefix\n"
             << "2 - Infix to Postfix\n"
             << "3 - Evaluate Prefix\n"
             << "4 - Evaluate Postfix\n"
             << "5 - Exit\n"
             << endl;
        int x;
        cout << "Enter which operation you want to perform : ";
        cin >> x;
        if (x == 5)
        {
            break;
        }

        switch (x)
        {
        case 1:
            cout << "Enter the Infix Value : ";
            cin >> infix;
            Infix_to_Prefix(infix, prefix);
            Display(prefix);
            break;
        case 2:
            cout << "Enter the Infix Value : ";
            cin >> infix;
            Infix_to_Postfix(infix, postfix);
            Display(postfix);
            break;
        case 3:
            cout << "Evaluating Prefix " << endl;
            Evaluate_Prefix(prefix);
            break;
        case 4:
            cout << "Evaluating Postfix " << endl;
            Evaluate_Postfix(postfix);
            break;

        default:
            break;
        }
    }
}