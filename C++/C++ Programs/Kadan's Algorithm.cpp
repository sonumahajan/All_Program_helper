#include<bits/stdc++.h>
using namespace std;


int main(){
	
  int a[]={2,-3,6,2,5,-2,4,10,6,-3};
  int n = sizeof(a)/sizeof(a[0]);

    int currsum=0;
    int oversum=0;

  for(int i=0;i<n;i++){
                                      
        if(currsum>=0)
        	currsum+=a[i];
        else
            currsum=a[i];
        	
        if(currsum>oversum)      	
       	oversum=currsum;
             
  }
	cout<<oversum;

	return 0;
}