
#include <iostream>
using namespace std;

int Min(int arr[], int n)
{
	int res = arr[0];
	for (int i = 1; i < n; i++)
		res = Min(res, arr[i]);
	return res;
}



int main()
{
	int arr[] = { 12, 1234, 45, 67, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum element of array: " << Min(arr, n)
		<< "\n";
	
	return 0;
}

