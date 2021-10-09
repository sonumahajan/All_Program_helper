package array;

//Rearrange array such that even index elements are smaller and odd index elements are greater

public class Rearrange_Array {

	void rearrangeNum(int[] arr, int n)
	{
		int temp;
		for(int i=0;i<n-1;i++)
		{
			if(i%2 == 0 && arr[i] > arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
			if(i%2 != 0 && arr[i]< arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}
	
	void printArray(int [] arr ,int n)
	{
		for(int i=0;i<n;i++)
		{
			System.out.println(arr[i] + " ");
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Rearrange_Array RA =new Rearrange_Array();
		int arr[]= {2,3,4,5};
		int arr1[]= {6,4,2,1,8,3};
	    int n = arr1.length;
		RA.rearrangeNum(arr1, n);
		RA.printArray(arr1, n);
		

	}

}
