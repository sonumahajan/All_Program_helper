#include<bits/stdc++.h>
using namespace std;

bool checkDuplicatesWithinK(int arr[], int n, int k)
{
	unordered_set<int> myset;

	for (int i = 0; i < n; i++)
	{
		if (myset.find(arr[i]) != myset.end())
			return true;

		myset.insert(arr[i]);

		if (i >= k)
			myset.erase(arr[i-k]);
	}
	return false;
}


int main ()
{
    int n;
    cout<<"Enter the size of array: \t";
    cin >> n;
	int arr[n];
    cout<<"\nEnter the elements of array: \n";
    for (int i=0; i<n ; i++){
        cin>>arr[i];
    }
	if (checkDuplicatesWithinK(arr, n, 3))
		cout << "Yes";
	else
		cout << "No";
}

