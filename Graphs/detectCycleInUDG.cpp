#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,vector <int> adj[],int parent,vector <int> &vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,node,vis)) return true;
            }
            else if(it!=parent) return true;
        }
        return false;
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector <int> vis(v+1,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                bool ans = dfs(i,adj,-1,vis);
                if(ans) return true;
            }
        }
        return false;
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends