#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
class Solution
{
public:
	void merge(int arr[], int l, int m, int r)
	{
		// Your code here
		int a[m - l + 1]; int b[r - m];
		for (int i = 0; i < m - l + 1; i++) {
			a[i] = arr[l + i];
		}
		for (int i = 0; i < r - m; i++) {
			b[i] = arr[m + 1 + i];
		}
		int i = 0, j = 0, k = l;
		while (i < m - l + 1 && j < r - m) {
			if (a[i] > b[j]) {
				arr[k] = b[j];
				j++; k++;
			}
			else {
				arr[k] = a[i];
				i++; k++;
			}
		}
		while (i < m - l + 1) {
			arr[k] = a[i];
			i++; k++;
		}
		while (j < r - m) {
			arr[k] = b[j];
			j++; k++;
		}
	}
public:
	void mergeSort(int arr[], int l, int r)
	{
		if (l < r) {
			int mid = (l + r) / 2;
			mergeSort(arr, l, mid);
			mergeSort(arr, mid + 1, r);
			merge(arr, l, mid, r);
		}
	}
};
int main()
{
	int n, T, i;

	scanf("%d", &T);

	while (T--) {

		scanf("%d", &n);
		int arr[n + 1];
		for (i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		Solution ob;
		ob.mergeSort(arr, 0, n - 1);
		printArray(arr, n);
	}
	return 0;
}