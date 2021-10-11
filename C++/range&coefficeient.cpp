#include<iostream>
#include<climits>
using namespace std;

void range(int arr[], int n)
{
    int min=INT_MAX;
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    

    cout<<"Range="<<max-min<<endl;
    cout<<((double)max-(double)min)/((double)max+(double)min);
    
}

// void display(int arr[], int n)
// {
//     for(int i=0;i<n;i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }


int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    range(arr, n);
    // display(arr, n);
}