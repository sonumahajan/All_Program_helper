    int minimumTotal(vector<vector<int>>& tri) {
        int n = tri.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        
        dp[0][0] = tri[0][0];
        
        for(int i=1; i<n; i++) {
            dp[i][0] = dp[i-1][0] + tri[i][0];
            dp[i][i] = dp[i-1][i-1] + tri[i][i];
        }
        
        for(int i=2; i<n && i<tri[i].size(); i++){
            for(int j=1; j<n && j<tri[i].size()-1; j++){ 
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + tri[i][j];
            }
        }
        
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
