#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int src,vector <int> &vis,vector <int> &order,vector <int> adj[]){
            vis[src]=1;
            order[src]=1;
            for(auto it:adj[src]){
                if(!vis[it]){
                    bool check = dfs(it,vis,order,adj);
                    if(check) return true;
                }
                else if(order[it]) return true;
            }
            order[src]=0;
            return false;
    }
    
    bool isCyclic(int v, vector<int> adj[]) {
        
        vector <int> vis(v,0);
        vector <int> order(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                bool ans = dfs(i,vis,order,adj);
                if(ans) return true;
            }
        }
        return false;
    }
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
