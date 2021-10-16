package array;

//to find common elements in given 3 sorted  arrays
//approach used
//we run a loop and traverse three arrays.
//Let the current element traversed in ar1[] be x, in ar2[] be y and in ar3[] be z. We can have following cases inside the loop.
//If x, y and z are same, we can simply print any of them as common element and move ahead in all three arrays.
//Else If x < y, we can move ahead in ar1[] as x cannot be a common element.
//Else If x > z and y > z), we can simply move ahead in ar3[] as z cannot be a common element.

public class CommonIn3Arrays {

	void findCommon(int []arr1,int [] arr2,int [] arr3)
	{
		int i=0 ,j=0 ,k=0;
		while(i< arr1.length && j<arr2.length && k<arr3.length)
		{
			// If x = y and y = z, print any of them and move ahead in all arrays 
			if(arr1[i] == arr2[j] && arr2[j] == arr3[k])
				{
				 System.out.println(arr1[i] + " ");
				 i++ ;
				 j++;
				 k++;
				}
			// x<y
			else if(arr1[i]<arr2[j])
				i++;

			//y<z
			else if(arr2[j]<arr3[k])
				j++;

			// We reach here when x > y and z < y, i.e., z is smallest
			else 
				k++;

		}

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		CommonIn3Arrays child =new CommonIn3Arrays();
		int arr1[]= {1,5,10,20,40,80};
		int arr2[]= {6,7,20,80,100};
		int arr3[]= {3,4,15,20,30,70,80,120};

		System.out.println("commom elements in 3 arrays are :" );
		child.findCommon(arr1, arr2, arr3);
	}


}
