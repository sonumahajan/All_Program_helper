public class FloorOfaNum {
    public static void main(String[] args) {
        int[] a = {-8, 5, 6, 8, 16};
        System.out.println(binarySearch(a,7));
    }
    private static int binarySearch(int[] a, int t) {
        int start = 0, end = a.length - 1;
        if(t<a[0])
            return -1;
        while (start<=end){
            int mid = start + (end-start)/2 ;
            if(t==a[mid])
                return mid;
            else if(t<a[mid])
                end = mid-1;
            else if (t>a[mid])
                start = mid+1;
        }
        return end;
    }
}
