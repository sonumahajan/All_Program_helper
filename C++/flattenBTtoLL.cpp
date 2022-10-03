/*
Problem link:
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr -> left != NULL) {
                // Find the inorder predecessor of current
                TreeNode* pre = curr -> left;
                while(pre -> right != NULL) {
                    pre = pre -> right;
                }
                // Link predecessor -> right to curr -> right
                pre -> right = curr -> right;
                // Link curr -> right to curr -> left
                curr-> right = curr -> left;
                // Remove link for curr -> left
                curr-> left = NULL;

            }
            curr = curr -> right;
        }
    }
};