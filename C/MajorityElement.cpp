#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
int find(int x,int n,int a[])
    {
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(x==a[i])
            f++;
        }
        if(f>n/2)
        return 1;
        else 
        return 0;
    }

    int majorityElement(int a[], int n)
    {
        if(n==1)
        return a[0];
        int c=1,maxc=0,maj;
        for(int i=0;i<n;i++)
        {
            if(a[maxc]==a[i])
            {
                c++;
                maj=a[i];
            }
            else
                c--;
            {
                if(c==0)
                {
                    c==1;
                    maxc=i;
                }
            }
        }
        if(find(a[maxc],n,a))
        return a[maxc];
        else 
        return -1;
    }
    int main()
    {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        {
        cin >> arr[i];
        }
    Solution obj;
    cout << obj.majorityElement(arr,n) <<endl;
    return 0;
    }
