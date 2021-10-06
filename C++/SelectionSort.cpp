#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size) {
  for (int j=0; j<size-1; j++) {
    int k=j;
    for (int i=j+1; i<size; i++) {
      if (arr[i]<arr[k])
          k=i;
    }
    swap(arr[k],arr[j]);
  }
}

int main() {
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    cout<<endl;
    int arr[n];
    cout<<"Enter elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selectionSort(arr,n);
    cout<<"Sorted array is :";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
 
}
