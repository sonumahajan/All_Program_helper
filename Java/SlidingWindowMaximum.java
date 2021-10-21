class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        PriorityQueue<Integer> pq=new PriorityQueue<Integer>(Collections.reverseOrder());
        int ans[]=new int[nums.length-k+1];
        for(int i=0;i<k;i++)
            pq.add(nums[i]);
        int index=0;
        ans[index]=(int)pq.peek();
        for(int i=k;i<nums.length;i++)
        {
            pq.add(nums[i]);
            pq.remove(nums[index]);index++;
            ans[index]=(int)pq.peek();
           // System.out.print(pq.peek()+",");
        }
        return ans;
    }
}
