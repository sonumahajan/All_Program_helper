public class BinaryTreesB {
    static class Node{
        int data;
        Node left;
        Node right;
        
        Node(int data)
        {
            this.data=data;
            this.left=null;
            this.right=null; 
        }
    }
        static class BinaryTree{
            static int idx=-1;
            public static Node buildTree(int nodes[])
            {
                idx++;
                if(nodes[idx]==-1)
                {
                    return null;
                }
                Node newNode =new Node(nodes[idx]);
                
                    newNode.left=buildTree(nodes);
                    newNode.right=buildTree(nodes);
                     
                return newNode;
                
            }
            public static void preorder(Node root)
            {
                if(root==null)
                    return;
            
            System.out.print(root.data+" ");
                preorder(root.left);
                preorder(root.right);
        }
             public static void inorder(Node root)
            {
                if(root==null)
                    return;
            
        
                inorder(root.left);
                  System.out.print(root.data+" ");
                inorder(root.right);
        }
             public static void postorder(Node root)
            {
                if(root==null)
                    return;
            
                postorder(root.left);
                postorder(root.right);
                System.out.print(root.data+" ");
        }
        }
    
    public static void main(String[] args) {
        int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        BinaryTree tree=new BinaryTree();
        Node root=tree.buildTree(nodes);
        System.out.println(root.data);
         System.out.print("Preorder : ");
        tree.preorder(root);
         System.out.print("Inorder : ");
        tree.inorder(root);
         System.out.print("Postorder : ");
        tree.postorder(root);
        
        
    }
}








// Output
/*
1
Preorder : 1 2 4 5 3 6 Inorder : 4 2 5 1 3 6 Postorder : 4 5 2 6 3 1
*/
