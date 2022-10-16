/*

Problem Link:
https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

*/

#include<iostream>
#include<limits.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this -> val = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

class Info {
    public:
    int sum;
    int maxi;
    int mini;
    bool isBST;
};

Info findLargestBST(TreeNode* root, int &maxSum) // Passing maxSum by reference
{ 
    // Base Case
    if(root == NULL) {
        return { 0, INT_MIN, INT_MAX, true };
    }

    // Finding info of left subtree using recursion
    Info leftSubtree = findLargestBST(root -> left, maxSum);
    // Finding info of right subtree using recursion
    Info rightSubtree = findLargestBST(root -> right, maxSum);

    // Info for current node
    Info currNode;
    currNode.maxi = max(root -> val, rightSubtree.maxi);
    currNode.mini = min(root -> val, leftSubtree.mini);
    currNode.sum = leftSubtree.sum + rightSubtree.sum + root -> val;
    if(leftSubtree.isBST && rightSubtree.isBST && (root -> val > leftSubtree.maxi) && (root -> val < rightSubtree.mini)) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }

    // Updating maximum size of the largest BST
    if(currNode.isBST) {
        maxSum = max(maxSum, currNode.sum);
    }

    return currNode;
}

int maxSumBST(TreeNode* root) {
    int maxSum = 0;
    Info temp = findLargestBST(root, maxSum);
    return maxSum;
}