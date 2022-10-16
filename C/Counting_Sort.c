// C Program for counting sort
/*Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array.
The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.
*/
#include<stdio.h>
#define MAX 255

void countSort(int array[], int size)
{
    int output[MAX];
    int count[MAX];
    int max = array[0];

    // Here we find the largest item in the array
    for (int i = 1; i < size; i++) { if (array[i] > max)
            max = array[i];
    }

    // Initialize the count for each element in array to 0
    for (int i = 0; i <= max; ++i)
	{
        count[i] = 0;
    }

    // For each element we store the count
    for (int i = 0; i < size; i++)
	{
        count[array[i]]++;
    }

    // Store the cummulative count of each array
    for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}
	
	// Search the index of each element of the actual array in count array, and
	// place the elements in output array
	for (int i = size - 1; i >= 0; i--) 
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Transfer the sorted items into actual array
    for (int i = 0; i < size; i++)
	{
        array[i] = output[i];
    }
}

// printing items of the array
void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ",array[i]);
    printf("\n");
}

// Driver code
int main() {
    int array[] = {2, 5, 2, 8, 1, 4, 1};
    int n = sizeof(array) / sizeof(array[0]);
  
    countSort(array, n);
  
    display(array, n);

    return 0;
}

//Output: 1 1 2 2 4 5 8
