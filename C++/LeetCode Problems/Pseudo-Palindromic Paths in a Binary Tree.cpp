class Solution {
public:
    int noOfPP=0;
    
    void dfs(TreeNode* root,int path[]){
        path[root->val]++;    
        if(root->left){
            dfs(root->left, path);
        }
        
        if(root->right){
            dfs(root->right, path);
        }
        if(root->left==nullptr && root->right==nullptr){
            int count=0;
            for(int i=1;i<=9;i++){
                if(path[i]%2 != 0){
                    count++;
                }
            }
            if(count <= 1){
                noOfPP++;
            }
        }
        path[root->val]--;  
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int path[10] ={0};
        dfs(root, path);
        return noOfPP;
    }
};