#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int trappingWater(int arr[], int n){
      int water=0;
      if(n<=2)
       return 0;
       vector<int> left(n,0), right(n,0);
        left[0]=arr[0];
       right[n-1]=arr[n-1];
       for(int i=1; i<n; i++){
       left[i]=max(left[i-1],arr[i]);
       right[n-i-1]= max(arr[n-i-1],right[n-i]);
    }
        for(int i=0;i<n;i++){
        water+=min(left[i],right[i])-arr[i];}
         return water;
      
    }
};
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        int a[n];
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
} 