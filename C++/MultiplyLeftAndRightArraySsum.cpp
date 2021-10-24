/****************************************

Pitsy needs help in the given task by her teacher. The task is to divide a array into two sub array (left and right) containing n/2 elements each and do the sum of the subarrays and then multiply both the subarrays.

Example 1:

â€‹Input : arr[ ] = {1, 2, 3, 4}
Output : 21
Explanation:
Sum up an array from index 0 to 1 = 3
Sum up an array from index 2 to 3 = 7
Their multiplication is 21.â€‹â€‹

â€‹Example 2:

Input : arr[ ] = {1, 2} 
Output :  2 
 

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function multiply() that takes an array (arr), sizeOfArray (n), and return the sum of the subarrays and then multiply both the subarrays. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ A[i] ≤ 100

*******************************************/

/************************************ SOLUTION ***************************************/

#include<iostream>
using namespace std;
int multsum(int ar[],int n)
{
    int lsum=0,rsum=0;
	    for(int i=0;i<n/2;i++)
	    {
	        lsum+=ar[i];
	    }
	    for(int i=n/2;i<n;i++)
	    {
	        rsum+=ar[i];
	    }
	    return lsum*rsum;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int ar[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>ar[i];
	    }
	    cout<<multsum(ar,n)<<"\n";
	}
	return 0;
}
