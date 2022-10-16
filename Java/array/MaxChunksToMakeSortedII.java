public class MaxChunksToMakeSortedII {
    public static void main(String[] args) {
        int[] arr=new int[]{2,1,3,4,4};

        //idea is to find a point . in  a sorted array   1 2 3 4 5 3 can be a break point to make a new chunk if all element on left is small 
        //than all people on right  , so have pre calculation of min on right and max on left
        
        int[] maxLeft=new int[arr.length];
        int[] minRight=new int[arr.length];
        maxLeft[0]=arr[0];
        for(int i=1;i<arr.length;i++){
            maxLeft[i]=Math.max(maxLeft[i-1],arr[i]);
        }
        minRight[arr.length-1]=arr[arr.length-1];
        for(int i=arr.length-2;i>=0;i--){
            minRight[i]=Math.min(maxLeft[i+1],arr[i]);
        }

        int cnt=1;
        for(int i=1;i<arr.length;i++){
            if(maxLeft[i-1]<=minRight[i]){
                cnt++;
            }

        }

        System.out.println(cnt);
        
    }
}
