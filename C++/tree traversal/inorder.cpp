/*  Algorithm Inorder(tree)
      1. Traverse the left subtree, i.e., call Inorder(left-subtree)
      2. Visit the root.
      3. Traverse the right subtree, i.e., call Inorder(right-subtree)
*/

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout << node->data << " ";
 
    /* now recur on right child */
    printInorder(node->right);
}
