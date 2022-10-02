// Code By- Romijul Laskar
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val) // constructor
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int height(struct node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left;
        int right;
        left = height(node->left);   // maximum height of the left subtree
        right = height(node->right); // maximum height of the right subtree
        if (left > right)
        {
            return left + 1;
        }
        else
            return right + 1;
    }
}
node *inorderSuccessor(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}
node *del(node *root, int val)
{
    if (root->data < val)
    {
        root->right = del(root->right, val);
    }
    else if (root->data > val)
    {
        root->left = del(root->left, val);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
}
void search(node *root, int val)
{
    if (root->data == val)
    {
        cout << setw(10) << "Found";
        exit(0);
    }
    while (root->data != val)
    {
        if (root->data < val)
        {
            search(root->right, val);
        }
        else
        {
            search(root->left, val);
        }
    }
}
node *insert(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    system("CLS");
    cout<<"********* BST *************\n";
    int i, n, val, c;
    node *root = NULL;
    // srand(time(0));
    cout << "How many nodes you want - ";
    cin >> n;
    cout<<"Enter "<<n<<" Keys - ";
    for (i = 0; i < n; i++)
    {
        // root = insert(root, rand() % 50); // by random numbers
        cin >> val;
        root = insert(root, val);
    }
    inorder(root);
here:
    cout << "\n1- Insert\n2- Delete\n3- Display(inorder)\n4- Height\n5- Search\n0- Exit\nYour choice - ";
    cin >> c;
    switch (c)
    {
    case 1:
        cout << "Enter number to insert - ";
        cin >> val;
        insert(root, val);
        inorder(root);
        break;
    case 2:
        cout << "Enter key to delete - ";
        cin >> val;
        del(root, val);
        inorder(root);
        break;
    case 3:
        inorder(root);
        break;
    case 4:
        cout << "\nheight is " << height(root);
        break;
    case 5:
        cout << "Enter number - ";
        cin >> val;
        search(root, val);
        break;
    case 0:
        return 0;
        break;
    default:
        cout << "Invalid Choice";
        break;
    }
    goto here;
}
