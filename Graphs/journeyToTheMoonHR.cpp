#include <bits/stdc++.h>
using namespace std;

vector<list<long long> > g; //Adjacency list of graph
vector<bool> visited;
long long vertices=0;
void DFS(long long u){
    if(visited[u]) return ;
    visited[u]=true;
    vertices++;
    for(auto i: g[u])
        if(!visited[i])
            DFS(i);
}
int main(){
    long long n,e,u,v;
    cin>>n>>e;
    long long ans=n*(n-1)/2; //Find all possibilities nC2 . 
    g.resize(n); //Resizing the graph again
    visited.resize(n,false); //Resizing visited array and marking again everything false.
    while(e--){
        cin>>u>>v;
        g[u].push_front(v); g[v].push_front(u);
    }
    for(long long i=0;i<n;i++){
        vertices=0;
        DFS(i);
        ans=ans-vertices*(vertices-1)/2;
    }
    cout<<ans;
    return 0;
}