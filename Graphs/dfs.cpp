#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs_helper(int node,vector <int> adj[],vector <int> &vis,vector <int> &ans){
        ans.push_back(node);
        vis[node]=1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs_helper(it,adj,vis,ans); 
            }
        }
    }
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector <int> ans;
        vector <int> vis(v+1,0);
        for(int i=0;i<v;i++) {
            if(!vis[i]) dfs_helper(i,adj,vis,ans); 
        }
        return ans;
    }
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  // } Driver Code Ends