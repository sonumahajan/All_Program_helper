import java.util.Scanner;

public class Selection_Sort {

	public static void selection_Sort(int[] arr) {
		// Your code goes here
		int start = 0;
		int end = (arr.length) - 1;
		for (int i = start; i <end; i++) {
			
			  for(int j=1;j<=end;j++){
				  if (arr[i]>arr[j]) {
					  int temp;
					  temp=arr[i];
					  arr[i]=arr[j];
					  arr[j]=arr[i];
					  break;
				  }
			  }

		}
		for (int i= 0 ; i < arr.length;i++) {
			System.out.print(arr[i] + " ");
		}

	}

	public static void main(String args[]) {
		int arr1[] = { 1, 3, 7, 9, 11, 12, 45 };
		Scanner sc = new Scanner(System.in);
		selection_Sort(arr1);
	}

}
