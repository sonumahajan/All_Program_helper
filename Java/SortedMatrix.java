//search in a sorted matrix
import java.util.Arrays;

public class SortedMatrix {
    public static void main(String[] args) {
        int[][] arr = {
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12}
        };
        System.out.println(Arrays.toString(search(arr,11)));
    }

    private static int[] binarySearch(int[][] matrix, int row, int cStart, int cEnd, int target){
        while (cStart<=cEnd){
            int mid = cStart + (cEnd-cStart)/2;
            if(matrix[row][mid]==target)
                return new int[] {row,mid};
            else if (matrix[row][mid]>target)
                cEnd-=1;
            else
                cStart+=1;
        }
        return new int[] {-1,-1};
    }
    private static int[] search(int[][] matrix, int target) {
        int row = matrix.length, col = matrix[0].length;
        int rStart = 0, rEnd = row-1,cmid = (col-1)/2;
        while(rStart<(rEnd-1)){ //condition for checking rows>2
            int mid = rStart + (rEnd-rStart)/2;
            if(matrix[mid][cmid]==target)
                return new int[] {mid, cmid};
            else if(matrix[mid][cmid]<target)
                rStart = mid;
            else
                rEnd = mid;
        }
        if(matrix[rStart][cmid]==target)
            return new int[] {rStart,cmid};
        if(matrix[rStart+1][cmid]==target)
            return new int[] {rStart+1,cmid};
        if(matrix[rStart][cmid-1]>=target)
            return binarySearch(matrix,rStart,0,cmid-1,target);
        if(matrix[rStart][cmid+1]<=target && matrix[rStart][col-1]>=target)
            return binarySearch(matrix,rStart,cmid+1,col-1,target);
        if(matrix[rStart+1][cmid-1]>=target)
            return binarySearch(matrix,rStart+1,0,cmid-1,target);
        return binarySearch(matrix,rStart+1,cmid+1,col-1,target);
    }
}
