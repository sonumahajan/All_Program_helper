#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

int MAX_INF[10];
bool visited[10];

struct node{
     vector<pair<int,int>> end;
        
};

struct node adj[10];

void BFS(int start){
  MAX_INF[start]=0;
  int temp=start;

   queue<int>q;
   q.push(start);
   visited[start]=0;
        
   while(!q.empty()){
        
         start=q.front();
         q.pop();

           for(auto i: adj[start].end){
              if(!visited[i.first]){
                if(MAX_INF[start]+i.second<MAX_INF[i.first]){
                  q.push(i.first);
                  visited[i.first];
                  MAX_INF[i.first]=MAX_INF[start]+i.second;
                }

              }
           }  
      }


}

void Dijiktra(int x,int y, int w){
      
   (adj[x].end).push_back(make_pair(y,w));
  (adj[y].end).push_back(make_pair(x,w));

}

int main(){

  
    //MAX_INF[0]=0;
int x,y,w;
int v,e;
cin>>v>>e;
 
  for(int i=0;i<e;i++){
    cin>>x>>y>>w;
    Dijiktra(x,y,w);
  }


for(int i=0;i<v;i++){
  fill_n(MAX_INF, 10 ,N);
  BFS(i);
cout<<i<<" -> ";
  for(int i=0;i<v;i++)
  cout<< MAX_INF[i]<<" ";


  cout<<endl;
}

  





// for(auto x: adj[2].end)
//  cout<<x.first<<" "<<x.second<<endl;

  return 0;
}














// queue<int>q;

//     visited[start]=true;
//     q.push(start);

//     while(!q.empty()){
          
//       start=q.front();
//       q.pop();
        
//       for(auto i:adj[start].end){
          

//              }

//            }
