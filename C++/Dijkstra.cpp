#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        // Code here
         int visited[n] = {false};
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        
        for(auto v : adj[u]){
            if( dist[v[0]] > dist[u] + v[1]){
                dist[v[0]] = dist[u] + v[1];
                pq.push({dist[v[0]], v[0]});
            }
        }
    }
    return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
