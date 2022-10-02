class Solution {
public:
    int dp[101][10001];
    int solve(int k,int n)
    {
        if(n==0||k==1||n==1)
            return n;
        if(dp[k][n]!=-1)
            return dp[k][n];
        int l=1;int h=n;
        int ans=INT_MAX;
        while(l<=h)
        {
        int mid=(l+h)/2;
        int left=solve(k-1,mid-1);
        int right=solve(k,n-mid);
        int temp=max(left,right)+1;
        if(left<right)
            l=mid+1;
        else if(left>=right)
            h=mid-1;
        ans=min(ans,temp);
        }
        return dp[k][n]=ans;
    }
    
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};
