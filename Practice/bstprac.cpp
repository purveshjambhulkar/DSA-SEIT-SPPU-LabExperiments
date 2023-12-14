#include <iostream>
#include <queue>
using namespace std;

/*) Insert (Handle insertion of duplicate entry) (DONE)  - ---------------
b) Delete(DONE)-------------
c) Search (DONE)----------------
d) Display tree (Traversal)(DONE)----------------
e) Display - Depth of tree-------------------
f) Display - Mirror image ---------------------
g) Create a copy--------------------
h) Display all parent nodes with their child nodes----------------------
i) Display leaf nodes(DONE)--------------------
j) Display tree level wise-------------------------- */

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void Insert(Node *&root, int d)
{

    if (root == NULL)
    {
        root = new Node(d);
        return;
    }

    if (root->data > d)
    {
        return Insert(root->left, d);
    }
    else if (root->data < d)
    {
        return Insert(root->right, d);
    }
}

void Display(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    Display(root->left);
    cout << root->data << " ";
    Display(root->right);
}

void Search(Node *root, int target)
{

    if (root == NULL)
    {
        return;
    }

    if (root->data == target)
    {
        cout << "Element found" << endl;
    }
    else if (root->data > target)
    {
        return Search(root->left, target);
    }
    else
    {
        return Search(root->right, target);
    }
}

int FindMin(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL)
    {
        return root->data;
    }

    return FindMin(root->left);
}

int FindMax(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    if (root->right == NULL)
    {
        return root->data;
    }

    return FindMax(root->right);
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
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (root->left)
            {
                q.push(root->left);
            }
            if (root->right)
            {
                q.push(root->right);
            }
        }
    }
}

int main()
{

    return 0;
}