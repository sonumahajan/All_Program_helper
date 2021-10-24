#include <bits/stdc++.h>
using namespace std;

//template <typename T>
class TreeNode
{
public:
    int data;
    vector< TreeNode* > children; //vector with TreeNode type pointer is created, name-> children

    TreeNode(int data)
    {
        this->data = data; //initialize the data portion of TreeNode object with the passed data
    }

    //-----TAKE INPUT FROM USER----
    
};
TreeNode* TakeInput()
    {
        int rootData=0;
        cout << "Enter root data " << endl;
        cin >> rootData;

        TreeNode* root = new TreeNode(rootData);
        int n=0;
        cout << "Enter number of children of " << rootData << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            TreeNode *child = TakeInput();
            root->children.push_back(child);
        }
        //cout<<root->children->data;
        return root;
    }

    //------PRINT TREE NODES---

    void printTree(TreeNode *root)
    {
        if (root == NULL)
            return;

        cout << root->data << ": ";
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ", ";
        }
        cout << endl;
        for (int i = 0; i < root->children.size(); i++)
        {
            printTree(root->children[i]);
        }
    }

int main()
{
    // TreeNode* root1 = new TreeNode(20);
    // cout<<root1->data;
    TreeNode * root =  TakeInput();
    printTree(root);
    return 0;
}
