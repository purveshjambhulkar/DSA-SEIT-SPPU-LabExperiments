#include <iostream>
using namespace std;

struct node
{
    node *next;
    char data;
};

class Stack
{

    node *top;
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

    void push(char x)
    {
        node *p = new node;
        p->data = x;
        p->next = top;
        top = p;
    }

    char pop()
    {
        node *p;
        char x;
        p = top;
        x = p->data;
        top = top->next;
        delete (p);
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
    else if (x == '-' || x == '+')
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

void Infix_to_Postfix(char infix[30], char postfix[30])
{

    Stack S;
    int i, j = 0;
    char token, x;
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
                S.push(token);
            }
            else if (token == ')')
            {
                while ((x = S.pop()) != '(')
                {
                    postfix[j] = x;
                    j++;
                }
            }
            else
            {
                while (S.isEmpty() != 1 && precedence(token) <= precedence(S.topdata()))
                {
                    postfix[j] = S.pop();
                    j++;
                }
                S.push(token);
            }
        }
    }

    while (S.isEmpty() != 1)
    {
        postfix[j] = S.pop();
        j++;
    }
    postfix[j] = '\0';
}

void reverse(char a[30], char b[30])
{
    int i, j = 0;
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i--;

    for (j = 0; i >= 0; i--)
    {
        if (a[i] == '(')
        {
            b[j] = ')';
            j++;
        }
        else if (a[i] == ')')
        {
            b[j] = '(';
            j++;
        }
        else
        {
            b[j] = a[i];
            j++;
        }
    }
    b[j] = '\0';
}

void Infix_to_Prefix(char infix[30], char prefix[30])
{
    char infix1[30], prefix1[30];
    reverse(infix, infix1);
    Infix_to_Postfix(infix1, prefix1);
    reverse(prefix1, prefix);
}

int evaluate(int op1, int op2, char op)
{
    if (op == '*')
    {
        return op1 * op2;
    }
    if (op == '+')
    {
        return op1 + op2;
    }
    if (op == '-')
    {
        return op1 - op2;
    }
    if (op == '/')
    {
        return op1 / op2;
    }
}

void Evaluate_Prefix(char prefix[30])
{
    Stack s;
    char token;
    int op1, op2;
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
            cout << "Enter the value of the " << token << endl;
            int x;
            cin >> x;
            s.push(char(x));
        }
        else
        {
            op1 = s.pop();
            op2 = s.pop();
            result = evaluate(op1, op2, token);
            s.push(char(result));
        }
    }
    int anee = s.pop();
    cout << anee;
}

void Evaluate_Postfix(char postfix[30])
{
    Stack s;
    char token;
    int op1, op2;
    int i;
    int result;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        token = postfix[i];
        if (isalnum(token))
        {
            cout << "Enter the value of the " << token << endl;
            int x;
            cin >> x;
            s.push(char(x));
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();
            result = evaluate(op1, op2, token);
            s.push(char(result));
        }
    }
    int anee = s.pop();
    cout << anee;
}
int main()
{

    char infix[30];
    char postfix[30];
    char prefix[30];

    // int op;

    // cin >> infix;
    // Infix_to_Postfix(infix, postfix);
    // cout << postfix << endl;
    // cout << "Evaluate Postfix\n";
    // Evaluate_Postfix(postfix);
    // cout << endl;
    // Infix_to_Prefix(infix, prefix);
    // cout << prefix << endl;
    // cout << "Evaluate Prefix\n";
    // Evaluate_Prefix(prefix);

    while (true)
    {
        cout << "Enter which operation you want to perform \n";
        cout << "1 - Infix To Postfix \n"
             << "2 - Infix To Prefix\n"
             << "3 - Evaluating Prefix\n"
             << "4 - Evaluating Postfix\n"
             << "5 - Exit\n"
             << endl;
        int a;
        cin >> a;
        if (a == 5)
        {
            break;
        }

        switch (a)
        {
        case 1:
            cout << "-----Infix To Postfix-----\n";
            cout << "Enter Infix Expression\n";
            cin >> infix;
            Infix_to_Postfix(infix, postfix);
            cout << "Postfix Expression : " << postfix << endl;
            cout << endl;
            break;
        case 2:
            cout << "-----Infix To Prefix-----\n";
            cout << "Enter Infix Expression\n";
            cin >> infix;
            Infix_to_Prefix(infix, prefix);
            cout << "Prefix Expression : " << prefix << endl;
            cout << endl;
            break;
        case 3:
            cout << "-----Evaluating Prefix-----\n";
            Evaluate_Prefix(prefix);
            cout << endl;
            cout << endl;
            break;
        case 4:
            cout << "-----Evaluating Postfix-----\n";
            Evaluate_Postfix(postfix);
            cout << endl;
            cout << endl;
            break;
        }
    }
}