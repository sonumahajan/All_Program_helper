#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(int i,int j,int vis[][501],vector<vector<char>>&grid,int n,int m){
         if(i<0 or j<0 or i>=n or j>=m) return; //Check boundary and base conditions
         if(grid[i][j]=='0') return; //If water then why to check
         
         if(!vis[i][j]){
            vis[i][j]=1; //Send dfs in all 8 directions.
            dfs(i+1,j,vis,grid,n,m);
            dfs(i-1,j,vis,grid,n,m);
            dfs(i,j+1,vis,grid,n,m);
            dfs(i,j-1,vis,grid,n,m);
            dfs(i+1,j+1,vis,grid,n,m);
            dfs(i-1,j-1,vis,grid,n,m);
            dfs(i+1,j-1,vis,grid,n,m);
            dfs(i-1,j+1,vis,grid,n,m);
         }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int vis[501][501]; //A visited matrix
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i][j]=0;
            }
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    dfs(i,j,vis,grid,n,m);
                    c++;
                }
            }
        }
        
        return c; //Return no of components. Here it signifies no of islands.
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends