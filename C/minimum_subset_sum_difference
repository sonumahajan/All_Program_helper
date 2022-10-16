#include<iostream>
#include<vector>
using namespace std;


void min_subset_sum_diff(int arr[], int n) 
{ 
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        sum=sum+arr[i];
    }
    int i, j; 
    int t[n + 1][(sum/2)+1]; 
    
    for (int i = 0; i <= n; i++) 
        t[i][0] = true; 

    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i < (sum/2)+1; i++) 
        t[0][i] = false; 
    //for understanding
    for (i = 1; i <= n; i++) { 
        for (j = 1; j < (sum/2)+1; j++) { 
            t[i][j]=0;
        } 
    }

    cout<<"Before DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j < (sum/2)+1; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl;

    
    for (int i = 1; i < n+1; i++) { 
        for (int j = 1; j < (sum/2)+1; j++) { 
            if(arr[i-1]<=j){
                //first check if block can be filled without current no. OR it with if it can be filled with current no and remaining sum be filled from above
                t[i][j]=( t[i-1][j-arr[i-1]] || t[i-1][j] );
            }
            else{
                //just use the above value from table
                t[i][j]= t[i-1][j];
            }

        } 
    }
    cout<<endl;

    // for understanding
    cout<<"After DP"<<endl;
    for (i = 0; i <= n; i++) { 
        for (j = 0; j < (sum/2)+1; j++) { 
            cout<<t[i][j]<<" ";
        } 
        cout<<endl;
    } 
    cout<<endl; 
    int diff=INT_MAX;
    for (int i = (sum/2); i >=0; --i)
    {
       if(t[n][i]==1){
            diff=sum-2*i;
            break;
        }
    }

    cout<<"Minimum Difference of 2 subsets sum =" <<diff;
    return;
}

int main(){
    int arr[] ={ 1,6,5,11 };
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout<<endl<<"MINIMUM SUBSET SUM DIFFERENCE USING DYNAMIC PROGRAMMING"<<endl;
    cout<<endl<<"GIVEN"<<endl<<"arr[] = { 1,6,5,11  }"<<endl<<"n = size of arr[]= 4"<<endl<<endl;
    cout<<"Find minimum difference between any 2 subsets. For ex- in this {1,11} - {6,5} = 1 is the minimum difference of 2 subsets"<<endl;
    cout<<"STEPS:"<<endl;
    cout<<"1. Create table with size n+1 and (sum/2)+1"<<endl<<"2. Initialize 1st row with 0 and 1st column with 1"<<endl<<"3. Start DP loop from 1st row 1st column i.e t[1][1]"<<endl;
    cout<<"4.OR operation btw take the current number and exclude the current number"<<endl<<"5.For last row in  table, run a loop from last column i.e sum/2. Check if the ith block is 1 or not. If it is, that means that sum is possible from the array. Store diff=sum-2*i in variable and break."<<endl<<"6. Return ans=diff(minimum difference of subsets)"<<endl<<endl;
    min_subset_sum_diff(arr,n);
}
