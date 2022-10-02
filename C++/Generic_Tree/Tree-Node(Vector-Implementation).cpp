#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode{
    public:                      
     T data;
     vector <TreeNode<T>*>children; //vector with TreeNode type pointer is created, name-> children

    TreeNode(T data)
    {
        this->data = data;   //initialize the data portion of TreeNode object with the passed data
    }
};

int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);  
    //creating root pointer of TreeNode type.
        // int n = new int;
        //int *n1 = new int;
        //TreeNode<int> *root = new TreeNode<int>(1)
    TreeNode<int>* node1 = new TreeNode<int>(2);  
    //creating node pointer in a same way as root
    TreeNode<int>* node2 = new TreeNode<int>(3);
    
    //------node1 is a pointer (dynamically created)
    //-------of class TreeNode
    //--------with data members --->data and children
    //---where, data is of type T(specified by user)
    //---- and children(pointer) is the name of the vector(containing TreeNode class k objects ka address i.e. address of data)

    root->children.push_back(node1);
    // pushing the node1 object in the vector(children) of root object of treenode class
    root->children.push_back(node2);
    // pushing the node2 object in the vector(children) of root object of treenode class
    // root's children filed is a vector that is why we are using pusg_back() function to push the object into it

    cout<<"root-> "<<root->data<<endl;
    cout<<"root's children are : ";
    for(int i=0;i<2;i++)
    {
        cout<<root->children[i]->data<<" ";
    }
}
