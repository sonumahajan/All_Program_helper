#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int a[], int arr_size)
{
	int low = 0;
	int high = arr_size - 1;
	int mid = 0;

	while (mid <= high) {
		switch (a[mid]) {
		case 0:
			swap(&a[low++], &a[mid++]);
			break;
		case 1:
			mid++;
			break;
		case 2:
			swap(&a[mid], &a[high--]);
			break;
		}
	}
}

void printArray(int arr[], int arr_size)
{
	int i;
	for (i = 0; i < arr_size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 0,2,1,0,0,1,2,1,0,0,2,1 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	sort(arr, arr_size);

	printf("Sorted Array: \n");
	printArray(arr, arr_size);

	return 0;
}
