#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        
        //Topological Sort using bfs
        
        vector <int> indegree(n,0);
        queue <int> q;
        vector <int> adj[n]; //To store the graph
        
        //Building the graph:
        
        for(int i=0;i<prereq.size();i++){
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }
        
        for(int i=0;i<n;i++){
	        for(auto it:adj[i]){
	            indegree[it]++; //To count the indegree of each node.
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0) q.push(i); //Push node having indegree 0
	    }
        
        vector <int> ans; //To store sorted order
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node); //Pushing nodes in the queue in topo order
	        
	        for(auto it:adj[node]){
	            indegree[it]--; //Removing the adjacent edges.
	            if(indegree[it]==0) q.push(it);
	        }
	    }
        
        if(ans.size()==n) return true;
        return false;
    }
};