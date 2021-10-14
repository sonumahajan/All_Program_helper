#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector <int> dist(v+1,INT_MAX);
        
        dist[s]=0;
        pq.push(make_pair(0,s));
        
        while(!pq.empty()){
            auto node = pq.top().second;
            auto nodedist = pq.top().first;
            pq.pop();
            
            for(auto nbr:adj[node]){
                if(nodedist+nbr[1]<dist[nbr[0]]){ 
                    //Check if current node dist + next dist is less than current.
                    dist[nbr[0]]=nodedist+nbr[1];
                    pq.push({dist[nbr[0]],nbr[0]});
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

  // } Driver Code Ends