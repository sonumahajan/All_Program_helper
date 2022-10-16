class Solution
{
    
    ArrayList <Integer> levelOrder(Node node) 
    {   
        ArrayList<Integer> a=new ArrayList<Integer>();
        Queue<Node> q= new LinkedList<Node>();
        q.add(node);
        while(!q.isEmpty()){
            Node curr=q.remove();
            a.add(curr.data);
            if(curr.left!=null)
            q.add(curr.left);
            if(curr.right!=null)
            q.add(curr.right);
        }
        return a;
    }
}
