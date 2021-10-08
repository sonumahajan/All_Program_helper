// sub array
// 2 3 4 5 6 

// 2
// 5
// 9
// 14
// 20

// 3
// 7
// 12
// 18

// ..
// ..


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    int curr=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {

        curr=0;
        for(int j=i;j<n;j++)
        {
            curr+=a[j];
            cout<<curr<<endl;
        }
    }
    return 0;
}
