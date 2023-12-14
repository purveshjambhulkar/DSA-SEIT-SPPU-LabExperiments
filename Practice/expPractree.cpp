#include <iostream>
#include <stack>
#include <queue>
using namespace std;

/*
Construct an Expression Tree from postfix and prefix expression. Perform
recursive and non- recursive In-order, pre-order and post-order traversals*/

class Node
{

public:
    char data;
    Node *left;
    Node *right;
    Node(char d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createPost(char postfix[20])
{ // ab*c/

    stack<Node *> s;
    Node *temp;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char token = postfix[i];

        if (isalnum(token))
        {
            temp = new Node(token);
            temp->left = NULL;
            temp->right = NULL;
            s.push(temp);
        }
        else
        {
            temp = new Node(token);
            temp->right = s.top();
            s.pop();
            temp->left = s.top();
            s.pop();
            s.push(temp);
        }
    }
    return s.top();
}

Node *createPre(char prefix[20])
{
    stack<Node *> s;
    Node *temp;
    int i;
    for (i = 0; prefix[i] != '\0'; i++)
    {
    }
    i--;

    for (; i >= 0; i--)
    {
        char token = prefix[i];
        if (isalnum(token))
        {
            temp = new Node(token);
            temp->left = NULL;
            temp->right = NULL;
            s.push(temp);
        }
        else
        {
            temp = new Node(token);
            temp->right = s.top();
            s.pop();
            temp->left = s.top();
            s.pop();
            s.push(temp);
        }
    }

    return s.top();
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);

    cout << root->data << " ";

    Inorder(root->right);
}
void Postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    Postorder(root->left);

    Postorder(root->right);
}

void Preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Preorder(root->left);

    Preorder(root->right);

    cout << root->data << " ";
}

void DisplayTree(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        if (NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(temp);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// NonRecursive Inorder
void InOrderNONrec(Node *root)
{

    stack<Node *> s;
    while (root != NULL)
    {
        s.push(root);
        root = root->left;
    }

    while (!s.empty())
    {
        root = s.top();
        s.pop();
        cout << root->data << " ";
        root = root->right;
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
    }
}

void PreOrderNONrec(Node *root)
{
    stack<Node *> s;
    while (root != NULL)
    {
        cout << root->data << " ";
        s.push(root);
        root = root->left;
    }

    while (!s.empty())
    {
        root = s.top();
        s.pop();
        root = root->right;
        while (root != NULL)
        {
            cout << root->data << " ";
            s.push(root);
            root = root->left;
        }
    }
}

int main()
{
}