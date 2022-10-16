    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>>dp(n,vector<int>(n));
        
        for(int i=0; i<n; i++) {
            dp[0][i] = mat[0][i];
        }
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++){
                dp[i][j] = min({dp[i-1][j], dp[i-1][max(0,j-1)], dp[i-1][min(n-1,j+1)]}) + mat[i][j];
            }
        }
        
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
