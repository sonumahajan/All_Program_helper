#include<stdio.h>

// MERGE SORT

void merge(int arr[], int low, int mid, int high) {
	int n1 = mid - low + 1;
	int n2 = high - mid;

	int L[n1], R[n2], i, j, k;

	for (i = 0; i < n1; i++)
		L[i] = arr[low + i];

	for (j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	i = j = 0;
	k = low;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		k++;
		i++;
	}
	while (j < n2) {
		arr[k] = R[j];
		k++;
		j++;
	}
}

void merge_sort(int arr[], int low, int high) {
	if (low < high) {
		int mid = low + (high - low) / 2;
		merge_sort(arr, low, mid);
		merge_sort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

int main()
{
	int arr[] = { 80, 90, 100, 40, 50, 30, 20, 70, 60, 10}, n = 10;

	merge_sort(arr, n);

	print_arr(arr, n);

	return 0;
}