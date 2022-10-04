import java.util.Arrays;

public class CylclicSort {
    public static void main(String[] args) {
        int[] arr = {3,5,2,1,4};
        cyclic(arr);
        System.out.println(Arrays.toString(arr));
    }

    private static void cyclic(int[] arr) {
        int i = 0;
        while (i < arr.length){
            int correct = arr[i]-1;
            if(i != correct)
                swap(arr,i,correct);
            else
                i++;
        }
    }

    private static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first]=arr[second];
        arr[second]=temp;
    }
}
