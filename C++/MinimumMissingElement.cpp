// Given a array, find the smallest missing positive number.
// Time Complexity -- O(n)
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no. of elements in Array : ";
    cin>>n;
    int a[n];
    cout<<"Enter Array Elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bool ch[n];
    for(int i=0;i<n;i++)
    {
        ch[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0 && a[i]<n)
        {
            ch[a[i]]=true;
        }
    }
    int flag=-1;
    for(int i=0;i<n;i++)
    {
        if(ch[i]==false)
        {
            flag=i;
            break;
        }
    }
    if(flag==-1)
    {
        cout<<"Minumum Missing Positive Element : "<<n;
    }
    else
    {
        cout<<"Minumum Missing Element : "<<flag;
    }
    return 0;
}
