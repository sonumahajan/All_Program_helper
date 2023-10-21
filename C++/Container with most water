//Initial template for C++

#include<iostream>
using namespace std;
int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long A[], int len)
{
    int l = 0;
    int r = len -1;
    int area = 0;

    while (l < r)
    {
        // Calculating the max area
        int mini=min(A[l], A[r]);
        area = max(area, (mini * (r - l)));

            if (A[l] < A[r])
                l += 1;

            else
                r -= 1;
    }
    return area;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends
