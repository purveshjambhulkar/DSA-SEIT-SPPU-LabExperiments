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

// Implementation of Binary Search Tree

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
/*****************************************************************/
// Inserting Element
Node *inserting(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = inserting(root->left, data);
    }
    else
    {
        root->right = inserting(root->right, data);
    }
    return root;
}

void Insert(Node *&root)
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    while (data != -1)
    {
        inserting(root, data);
        cout << "Enter Node : ";
        cin >> data;
        if (data == -1)
        {
            break;
        }
    }
    cout << "Data Inserted" << endl;
}
/*****************************************************************/
// Delete
int FindMIN(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}
Node *Delete(Node *root, int element)
{

    Node *temp;
    if (root == NULL)
    {
        cout << "Tree is Empty !!" << endl;
        return NULL;
    }

    if (root->data > element)
    {
        root->left = Delete(root->left, element);
    }
    else if (root->data < element)
    {
        root->right = Delete(root->right, element);
    }
    else
    {
        // 2 child
        if (root->left && root->right)
        {
            int Min = FindMIN(root->right);
            root->data = Min;
            root->right = Delete(root->right, element);
        }
        else // less than 2 child
        {
            temp = root;
            if (root->right == NULL && root->left != NULL)
            {
                root = root->left;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                root = root->right;
            }
            delete temp;
        }
    }
    return root;
}

/*****************************************************************/
// Searching
bool Search(Node *&root, int target)
{

    if (root == NULL)
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
/*****************************************************************/
// Display Tree

void Display(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
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
/*****************************************************************/
// Depth of the Tree
int DepthofTree(Node *root)
{
    int hl, hr;
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL & root->right == NULL)
    {
        return 0;
    }
    hl = DepthofTree(root->left);
    hr = DepthofTree(root->right);

    if (hl > hr)
    {
        return hl + 1;
    }
    else
    {
        return hr + 1;
    }
}

/*****************************************************************/
// Display Mirror Image
Node *DisplayMirror(Node *root)
{
    Node *tempMirror;
    if (root == NULL)
    {
        return NULL;
    }

    tempMirror = root->left;
    root->left = DisplayMirror(root->right);
    root->right = DisplayMirror(tempMirror);

    return root;
}
/*****************************************************************/
// Copy
Node *CopyTree(Node *root)
{
    Node *copytemp = NULL;

    while (root != NULL)
    {
        copytemp = new Node(root->data);
        copytemp->left = CopyTree(root->left);
        copytemp->right = CopyTree(root->right);
    }

    return copytemp;
}
/*****************************************************************/
// display parent nodes with their child
void DisplayParentwithChild(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right != NULL)
    {
        cout << "\t" << root->data;
        cout << "\t" << root->right->data;
        cout << "\n";
    }

    if (root->left != NULL && root->right == NULL)
    {
        cout << "\t" << root->data;
        cout << "\t" << root->left->data;
        cout << "\n";
    }

    if (root->left != NULL && root->right != NULL)
    {
        cout << "\t" << root->data;
        cout << "\t" << root->left->data << "\t" << root->right->data;
        cout << "\n";
    }

    DisplayParentwithChild(root->left);
    DisplayParentwithChild(root->right);
}

/*****************************************************************/
// Display Leaf Nodes
void DislayLeafNodes(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        // Checking if it is a leaf Node
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

/*****************************************************************/
int main()
{
    Node *root = NULL;
    cout << "-----Binary Tree-----" << endl;
    cout << "Enter which operation you want to perform" << endl;
    // cout << "1 - Insertion\n"
    //      << "2 - Deletion\n"
    //      << "3 - Display Tree\n"
    //      << "4 - Search\n"
    //      << "5 - Display Leaf Nodes\n"
    //      << "6 - Depth of the Tree\n"
    //      << "7 - Mirror \n"
    //      << "8 - Coping\n"
    //      << "9 - DisplayParentwithChild\n"
    //      << endl;

    int op;

    while (true)
    {
        cout << "1 - Insertion\n"
             << "2 - Deletion\n"
             << "3 - Display Tree\n"
             << "4 - Search\n"
             << "5 - Display Leaf Nodes\n"
             << "6 - Depth of the Tree\n"
             << "7 - Mirror \n"
             << "8 - Coping\n"
             << "9 - DisplayParentwithChild\n"
             << endl;

        cout << "Enter valid operation : ";
        cin >> op;
        if (op == 11)
        {
            break;
        }

        switch (op)
        {
        case 1:
        {
            cout << "----Insertion----" << endl;
            Insert(root);
            cout << "Data Inserted in the BST" << endl;
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "----Deletion----" << endl;
            int ele;
            cout << "Enter the Node you want to Delete : ";
            cin >> ele;
            Delete(root, ele);
            cout << "Node Deleted from the BST" << endl;
            cout << endl;
            break;
        }
        case 3:
        {
            cout << "----Display Tree----" << endl;
            Display(root);
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "----Searching----" << endl;
            int target;
            cout << "Enter the element you want to Search : ";
            cin >> target;
            if (Search(root, target))
            {
                cout << "Element Found in the Tree " << endl;
            }
            else
            {
                cout << "Element Not Found" << endl;
            }
            cout << endl;
            break;
        }
        case 5:
        {
            cout << "----Display Leaf Nodes----" << endl;
            DislayLeafNodes(root);
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "----Display Depth of the Tree----" << endl;
            int depthx = DepthofTree(root);
            cout << "Depth : " << depthx << endl;
            cout << endl;
            break;
        }
        case 7:
        {
            cout << "----Mirroring Tree----" << endl;
            Node *MirrorTree = DisplayMirror(root);
            cout << endl;
            break;
        }
        case 8:
        {
            cout << "----Coping Tree----" << endl;
            Node *Copy = CopyTree(root);
            cout << endl;
            break;
        }
        case 9:
        {
            cout << "----Diplay Parent Nodes with Child----" << endl;
            DisplayParentwithChild(root);
            cout << endl;
            break;
        }
        }
    }
}