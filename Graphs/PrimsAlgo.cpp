#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//Prim's Algo
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector <int> key(V,INT_MAX);
        vector <int> parent(V,-1);
        vector <bool> mstSet(V,false);
        
        //We need 3 arrays to solve this
        //Parent array has the mst
        //Key array has all the wts.
        
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        
        key[0]=0;
        parent[0]=-1;
        pq.push({0,0}); //(dist,node)
        
        while(!pq.empty()){
            int u= pq.top().second; //Finding min wt. node
            pq.pop();
            mstSet[u]=true;
            
            for (auto nbr : adj[u]) {
            int v = nbr[0];
            int weight = nbr[1];
                if (mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
		            key[v] = weight; 
                    pq.push({key[v], v});    
                }
            }
            
        }
        
        int ans=0;
        for(int i=1;i<V;i++){
            ans+=key[i];
        }
        
        return ans;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends