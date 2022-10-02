struct Node {
    int data;
    Node *left, *right;
};
class Solution{
  public:
    void inorder(Node *root, vector<int> &ans){

      if(!root){

          return ;

      }

      inorder(root->left, ans);

      ans.push_back(root->data);

      inorder(root->right, ans);

  }

  void postOrder(Node *root, vector<int> &ans, int &idx){

      if(!root){

          return ;

      }

      postOrder(root->left, ans, idx);

      postOrder(root->right, ans, idx);

      root->data = ans[idx++];

  }

    void convertToMaxHeapUtil(Node* root)

    {

        // Your code goes here

        int idx = 0;

        vector<int> ans;

        inorder(root, ans);

        postOrder(root, ans, idx);

    }        
};

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string inp, ch;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution ob;
        ob.convertToMaxHeapUtil(root);
        postorderTraversal(root);
        cout << "\n";
    }
    return 0;
}
