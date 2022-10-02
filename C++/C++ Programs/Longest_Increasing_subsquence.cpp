#include<bits/stdc++.h>
using namespace std;

int LIS(int *a,int n){
    int list[n];
    int mx=-1;
    vector<int>v;
    fill_n(list,n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<=i-1;j++){

            if(a[i]>a[j]){
                 list[i]=max(list[j]+1,list[i]); 

                       if(mx<list[i])
                         mx=list[i];
                         //     if(list[i]>mx){
                         //        cout<<mx<<" ";
                         //        mx=list[i];  
                         //        v.push_back(a[i]);
                         // }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<list[i]<<" ";
    return mx;
}

int main(){

    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<endl<<"Longest increasing Substring: "<<LIS(a,n);

    return 0;
}