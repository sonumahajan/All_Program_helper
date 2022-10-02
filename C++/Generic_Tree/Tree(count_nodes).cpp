#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector< TreeNode<T>* > children; //vector with TreeNode type pointer is created, name-> children

    TreeNode(T data)
    {
        this->data = data; //initialize the data portion of TreeNode object with the passed data
    }

    //-----TAKE INPUT FROM USER----
    
};
//template <typename T>
TreeNode<int> * TakeInputLevelWise()
    {
        int rootData=0;
        cout<<"Enter root data "<<endl;
        cin>>rootData;
        TreeNode<int>* root = new TreeNode<int>(rootData);

        queue<TreeNode<int>*> pendingNodes;
        pendingNodes.push(root);

        while(pendingNodes.size()!=0)
        {
            TreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            cout<<"Enter number of children of front data "<<front->data<<endl;
            int numchild;
            cin>>numchild;

            for(int i=0;i<numchild;i++)
            {
                int childdata;
                cout<<"Enter child of "<<front->data<<endl;
                cin>>childdata;
                TreeNode<int>* child = new TreeNode<int> (childdata);
                front->children.push_back(child);
                pendingNodes.push(child);
            }
        }
        //cout<<root->children->data;
        return root;
    }

    //------PRINT TREE NODES---

    void printTree(TreeNode<int> *root)
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

    int countnodes(TreeNode<int>* root)
    {
        int mxh=1;
        int ans=1;
        for(int i=0;i<root->children.size();i++)
        {
            ans+=countnodes(root->children[i]);
        }
        
        return ans;
    }

int main()
{
    // TreeNode* root1 = new TreeNode(20);
    // cout<<root1->data;
    TreeNode<int> * root =  TakeInputLevelWise();
    printTree(root);
    cout<<"number of nodes : "<<countnodes(root);
    return 0;
}
