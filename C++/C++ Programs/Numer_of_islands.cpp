#include <bits/stdc++.h>
using namespace std;

int main(){
   int m,n;
    cin>>m>>n;
   vector<vector<char>>a(m,vector<char>(n));
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cin>>a[i][j];
      }
    }

 auto check = [&](int x,int y){  return x>=0 && x<m && y>=0 && y<n ; };


vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

 function<void(int,int,int)> DFS = [&](int x,int y,int cnt){
                 a[x][y]='$';

                
                      for(auto &g : dir){
                             int newi = x+g.first, newj = y+g.second;
                                if(check(newi,newj)  and a[newi][newj]=='1'){
                                       
                                        DFS(newi,newj,++cnt);
                                       }
                                      
                   }
                    cout<<cnt;
                   
                        
};

int cnt=0;
for(int i=0;i<m;i++){
  for(int j=0;j<n;j++){
    if(a[i][j]=='1'){
      int ans=0;

        




      DFS(i,j,0);

       cout<<ans<<" ";
    }
  }
}
cout<<cnt<<endl;

 for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }



  return 0;
}