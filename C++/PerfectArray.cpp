/***********************************************************************

There is an array contains some non-negative integers. Check whether the array is perfect or not. An array is called perfect if it is first strictly increasing, then constant and finally strictly decreasing. Any of the three parts can be empty.

 

Example 1:

Input : Arr[] = {1, 8, 8, 8, 3, 2}
Output : Yes
Explanation:
We have an array [1, 8, 8, 8, 3, 2]. 
If we look in the range [0, 1] then 
we find that in this range the array is 
increasing, in the range [1, 3] the array 
is constant and in the range [3, 4] the 
array is decreasing.So, it satisfies the above 
condition then we return true.

Example 2:

Input : Arr[] = {1, 1, 2, 2, 1}
Output : No

Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function checkUnimodal() that takes an array (arr), sizeOfArray (n), and return bool value that is true if condition satisfied else false. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
 

Constraints:
1 ≤ N ≤ 105
1 ≤ ai ≤ 108

**************************************************************************/

/****************************** SOLUTION ************************************/

#include<iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	      int i = 1; 
          while (arr[i] > arr[i - 1] && i < n) 
          ++i; 
        while (arr[i] == arr[i - 1] && i < n) 
        ++i; 
        while (arr[i] < arr[i - 1] && i < n) 
        ++i; 
    if(i==n)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
	}
	return 0;
}
