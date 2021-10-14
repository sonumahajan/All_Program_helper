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

    void preorder(TreeNode<int>* root)
    {
        if(root==NULL)
          return;

        cout<<root->data<<" ";
        for(int i=0;i<root->children.size();i++)
        {
            preorder(root->children[i]);
        }
    }

    void postorder(TreeNode<int>* root)
    {
        if(root==NULL)
          return;
        for(int i=0;i<root->children.size();i++)
        {
            postorder(root->children[i]);
        }

        cout<<root->data<<" ";
    }

    pair< TreeNode<int>* , int > node_max(TreeNode<int>* root)
    {
        int ans = root->data;
        pair< TreeNode<int>* , int > p;
        p.first = root;
        int child_ans = 0;
        for(int i=0 ; i<root->children.size() ; i++ )
        {
            child_ans += root->children[i]->data;
        }
        int final_ans = ans + child_ans;
        
        p.second = final_ans;

        for(int i=0 ; i< root->children.size() ; i++ ){
            pair< TreeNode<int>* , int > rec_ans = node_max(root->children[i]);
            if(p.second < rec_ans.second)
             {
                p.second = rec_ans.second;
             }
        }
        return p;
    }

int main()
{
    TreeNode<int> * root =  TakeInputLevelWise();
    printTree(root);
    //preorder(root);
    cout<<endl;
    //postorder(root);
    //cout<<node_max(root);

    pair< TreeNode<int>* , int > p1;
    p1 = node_max(root);
    cout<<p1.first->data<<" "<<p1.second;
    return 0;
}
