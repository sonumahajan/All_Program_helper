#include <bits/stdc++.h>
using namespace std;

//Storing graph in the form of adjacency list.

int main(){

    int v,e; //Vertex and edges
    cin>>v>>e;

    vector <int> g[v+1]; //A vector of array of int of size (v+1)

    //If wts then we will declare a vector of array of pair of int of size (v+1)

    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x); //If it is a bi-directional graph.
    }

    return 0;

}