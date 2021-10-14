#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    //We'll be basically using bfs to solve this problem.
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];
	    
	    int a[1001][1001]; //Due to constraints.
	    if(x1==x2 and y1==y2) return 0;
	    //Base condition if target and initial pos are same.
	    
	    //We mark the entire chess board 0 i.e unvisited.
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            a[i][j]=0;  //To store no. of steps
	        }
	    }
	    
	    queue <pair<int,int>>q;
	    //Pushing the source node
	    q.push(make_pair(x1-1,y1-1)); //To ensure 0 based indexing.
	    
	    while(!q.empty()){
	        auto cur = q.front();
	        int i = cur.first;
	        int j = cur.second;
	        q.pop();
	        
	        //We are basically checking the base conditions and also checking if it is feasible to reach the target node.Also there are only 8 possibilities.
	        if((i+1)>=0 and (i+1)<n and (j+2)>=0 and (j+2)<n and a[i+1][j+2]==0){
	            a[i+1][j+2] = a[i][j] + 1; //Theses are steps.
	            q.push(make_pair(i+1,j+2));
	        }
	        if((i-1)>=0 and (i-1)<n and (j+2)>=0 and (j+2)<n and a[i-1][j+2]==0){
	            a[i-1][j+2] = a[i][j] + 1;
	            q.push(make_pair(i-1,j+2));
	        }
	        if((i-2)>=0 and (i-2)<n and (j+1)>=0 and (j+1)<n and a[i-2][j+1]==0){
	            a[i-2][j+1] = a[i][j] + 1;
	            q.push(make_pair(i-2,j+1));
	        }
	        if((i+2)>=0 and (i+2)<n and (j+1)>=0 and (j+1)<n and a[i+2][j+1]==0){
	            a[i+2][j+1] = a[i][j] + 1;
	            q.push(make_pair(i+2,j+1));
	        }
	        if((i-1)>=0 and (i-1)<n and (j-2)>=0 and (j-2)<n and a[i-1][j-2]==0){
	            a[i-1][j-2] = a[i][j] + 1;
	            q.push(make_pair(i-1,j-2));
	        }
	        if((i+1)>=0 and (i+1)<n and (j-2)>=0 and (j-2)<n and a[i+1][j-2]==0){
	            a[i+1][j-2] = a[i][j] + 1;
	            q.push(make_pair(i+1,j-2));
	        }
	        if((i-2)>=0 and (i-2)<n and (j-1)>=0 and (j-1)<n and a[i-2][j-1]==0){
	            a[i-2][j-1] = a[i][j] + 1;
	            q.push(make_pair(i-2,j-1));
	        }
	        if((i+2)>=0 and (i+2)<n and (j-1)>=0 and (j-1)<n and a[i+2][j-1]==0){
	            a[i+2][j-1] = a[i][j] + 1;
	            q.push(make_pair(i+2,j-1));
	        }
	    }
	    
	    return a[x2-1][y2-1];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends