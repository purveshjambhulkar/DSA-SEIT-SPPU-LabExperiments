#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

Node *createPost(char postfix[20]) // ab*c/
{
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

Node *CreatePre(char prefix[20])
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

// Recursive
void InorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}
void PostorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
}
void PreorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
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

// NON Recursive Traversal
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
    char PostFix[20] = "ab*c/";
    char Prefix[20] = "*a/bc";
    // Node *root = NULL;

    Node *PostRoot = createPost(PostFix);

    // cout << "Inorder Traversal : ";
    // InorderTraversal(PostRoot);
    // cout << endl;
    // cout << "Postorder Traversal : ";
    // PostorderTraversal(PostRoot);
    // cout << endl;
    // cout << "Preorder Traversal : ";
    // PreorderTraversal(PostRoot);
    // cout << endl;
    // cout << endl;
    // cout << "Printing Level Order Traversal\n";
    // LevelOrderTraversal(PostRoot);
    // cout << endl;

    cout << endl;
    cout << "Non-Recursive Inorder Traversal : ";
    InOrderNONrec(PostRoot);
    cout << endl;
    cout << "Non-Recursive Preorder Traversal : ";
    PreOrderNONrec(PostRoot);

    Node *PreRoot = CreatePre(Prefix);
    // cout << "Inorder Traversal : ";
    // InorderTraversal(PreRoot);
    // cout << endl;
    // cout << "Postorder Traversal : ";
    // PostorderTraversal(PreRoot);
    // cout << endl;
    // cout << "Preorder Traversal : ";
    // PreorderTraversal(PreRoot);
    // cout << endl;
    // cout << endl;
    // cout << "Printing Level Order Traversal\n";
    // LevelOrderTraversal(PreRoot);
    // cout << endl;
}