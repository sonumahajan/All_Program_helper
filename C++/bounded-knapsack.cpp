//for reference go to - https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/ 

#include<bits/stdc++.h>

using namespace std;
#define int long long

int dp[102][102];

// recursive + memoization
int knapsackrcmemo(vector<int> wt, vector<int> val, int w, int n){
    if(n==0||w==0)
        return 0;
    if(dp[n][w]!=-1)
        return  dp[n][w];
    else if(wt[n-1]<=w){
        dp[n][w]=max(val[n-1] + knapsackrcmemo(wt, val, w-wt[n - 1], n-1), knapsackrcmemo(wt, val, w, n-1));
        //cout<<dp[n][w]<<" -"<<endl;
        return dp[n][w];
    }
    else if(wt[n-1]>w){
        dp[n][w]=knapsackrcmemo(wt, val, w, n-1);
        //cout<<dp[n][w]<<" --"<<endl;
        return dp[n][w];
    }
    return 0;
}

int knapsacktopdown(vector<int> wt, vector<int> val, int w, int n){

    int altdp[n+1][w+1];

    // modify base case condition to initilise matrix of top down 
    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){
            if(i==0 || j==0)
                altdp[i][j]=0;
        }
    }
    // modify hypothesis of rescurcive condtion to iterative
    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wt[i-1]<=j){
                altdp[i][j]=max(val[i-1]+altdp[i-1][j-wt[i-1]],altdp[i-1][j]);
            }else{
                altdp[i][j]=altdp[i-1][j];
            }
        }
    }

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<w+1; j++){
    //         cout<<altdp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return altdp[n][w];
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n,w;
    cin>>n;
    vector<int> wt(n);
    vector<int> val(n);
    for(int i=0; i<n; i++)
        cin>>wt[i];
    for(int i=0; i<n; i++)
        cin>>val[i];
    cin>>w;
    cout<<"recursive+memoization- "<<knapsackrcmemo(wt, val, w, n)<<endl<<"top down dp- "<<knapsacktopdown(wt, val, w, n);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
