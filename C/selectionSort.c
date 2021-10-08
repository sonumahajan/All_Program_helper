/*
	Author : Shaleen Badola
	Date : 08/10/2021
	Description : Selection sort algorithm in c
*/

/*
   Consider N = number of elements in the input array
   Time Complexity : O(N^2)
   Space Complexity : O(N)
*/


#include <stdio.h>

//     Funtion for selection sort
void selection(int arr[], int n) {
	int i, j, small;

	for (i = 0; i < n - 1; i++) {
		small = i;

		// find the next smallest element
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[small]) {
				small = j;
			}
		}

		// swap the current element to the next smallest element
		int temp = arr[small];
		arr[small] = arr[i];
		arr[i] = temp;
	}
}

// Function to print the array
void printArr(int a[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}

int main() {
	int a[] = { 12, 31, 25, 8, 32, 17 };

	int n = sizeof(a) / sizeof(a[0]);

	printf("Before sorting array elements are - \n");
	printArr(a, n);

	// Calling selection sort
	selection(a, n);

	printf("\nAfter sorting array elements are - \n");
	printArr(a, n);

	return 0;
}
