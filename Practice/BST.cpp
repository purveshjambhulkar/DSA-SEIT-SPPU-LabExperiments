#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int d)
    {
        this->data = d;
        right = NULL;
        left = NULL;
    }
};
/*************************************************************/
// Inserting
void Insert(Node *&root, int ele)
{
    if (root == NULL)
    {
        root = new Node(ele);
        return;
    }

    if (root->data > ele)
    {
        return Insert(root->left, ele);
    }
    else
    {
        return Insert(root->right, ele);
    }
}

void Display(Node *root)
{
    // Displaying Tree in Inorder

    if (root == NULL)
    {
        //     cout << "Tree Empty" << endl;
        return;
    }

    Display(root->left);
    cout << root->data << " ";
    Display(root->right);
}

bool Search(Node *root, int target)
{

    if (root == nullptr)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if (root->data > target)
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

Node *Delete(Node *root, int del)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == del)
    {
        // 2child
        if (root->right != NULL && root->left != NULL)
        {

            int mini = FindMin(root->right);
            root->data = mini;
            root->right = Delete(root->right, del);
            return root;
        }

        // less than 2 child
        Node *temp = root;
        if (root->left != NULL)
        {
            root = root->left;
        }
        else if (root->right != NULL)
        {
            root = root->right;
        }
        else
        {
            root = NULL;
        }
        delete temp;
        return root;
    }
    else if (root->data > del)
    {
        root->left = Delete(root->left, del);
        return root;
    }
    else
    {
        root->right = Delete(root->right, del);
        return root;
    }
}

void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

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

void DisplayLeadNodes(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    // q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // cout << endl;
            // if (!q.empty())
            // {
            //     q.push(NULL);
            // }
        }
        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                cout << temp->data << " ";
            }

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
int DepthOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    int hl;
    int hr;

    hr = DepthOfTree(root->right);
    hl = DepthOfTree(root->left);

    if (hl > hr)
    {
        hl++;
        return hl;
    }
    else
    {
        hr++;
        return hr;
    }
}

void DisplayParentWithChild(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL && temp->right != NULL)
        {
            cout << " " << temp->data << " " << endl;
            cout << temp->left->data << " ";
            cout << temp->right->data;
            cout << endl;
            cout << endl;
        }
        else if (temp->left == NULL && temp->right != NULL)
        {
            cout << " " << temp->data << " " << endl;
            cout << "  " << temp->right->data;
            cout << endl;
            cout << endl;
        }
        else if (temp->left != NULL && temp->right == NULL)
        {
            cout << " " << temp->data << " " << endl;
            cout << temp->left->data;
            cout << endl;
            cout << endl;
        }
        else
        {
            cout << " " << temp->data << " ";
            cout << endl;
            cout << endl;
        }

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

Node *Copy(Node *root)
{
    Node *copy = NULL;
    if (root != NULL)
    {
        copy = new Node(root->data);
        copy->left = Copy(root->left);
        copy->right = Copy(root->right);
    }
    return copy;
}

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

int main()
{
    Node *root = NULL;
    Insert(root, 5);
    Insert(root, 4);
    Insert(root, 8);
    Insert(root, 1);
    Insert(root, 9);
    Insert(root, 44);

    Display(root);
    cout << endl;

    while (true)
    {
        int op;
        cout << "Enter what you want to perform\n";
        cin >> op;
//THIS SWITCH CASE STATEMENT IS INCOMPLETE HEHEHEHE
        switch (op)
        {
        case 1:
            cout << "Enter how many Nodes you want insert :";
            int no;
            cin >> no;
            for (int i = 0; i < no; i++)
            {
                cout << "Enter the Node : ";
                int elex;
                cin >> elex;
                Insert(root, elex);
            }
            cout<<"Nodes Inserted\n";
            break;

        case 2:
            cout << "Displaying tree"<<endl;
            Display(root);
            break;

        case 3:
            cout << "Displaying tree"<<endl;
            Display(root);
            break;
        default:
            break;
        }
    }

    // cout << "searching" << endl;
    // if (Search(root, 5))
    // {
    //     cout << "Element Found\n";
    // }
    // else
    // {
    //     cout << "NotFound\n";
    // }
    // int Mini;
    // Mini = FindMin(root);
    // cout << "Min : " << Mini << endl;
    // int Mxi = FindMax(root);
    // cout << "Max : " << Mxi << endl;

    // Delete(root, 1);

    // Display(root);
    // cout << endl;
    // Delete(root, 44);
    // Display(root);

    // cout << endl
    //      << "Printing Level Order Tree\n";
    // LevelOrderTraversal(root);

    // cout << endl
    //      << "Leaf Nodes are : ";
    // DisplayLeadNodes(root);
    cout << endl;

    // int dpt = DepthOfTree(root);
    // cout << "depth : " << dpt << endl;

    // cout << "Printing Parent with their Child\n";
    // DisplayParentWithChild(root);
    // cout << endl;

    cout << "Inorder Traversal \n";
    InorderTraversal(root);
    cout << endl;
    cout << "postorder Traversal \n";
    PostorderTraversal(root);
    cout << endl;
    cout << "preorder Traversal \n";
    PreorderTraversal(root);
    cout << endl;
}