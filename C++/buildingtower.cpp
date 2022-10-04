#include <iostream>
#include<bits/stdc++.h>
using namespace std;
  void longestPalindrome(string &s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n1=s.length();int len=0;
        vector<vector<int>>dp(n1+1,vector<int>(n1+1,0));
        for(int i=0;i<=n1;i++)
        {
            dp[i][0]=0;
        }
        int ans=0;
          for(int i=0;i<=n1;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n1;j++)
            {
                if(s[i-1]==r[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
            len=ans;
        }
    	cout<<len;
        int ind=len-1;
        string res="";
        for(int i=0;i<len;i++)
        {
            res+="#";
        }
        int i=n1,j=n1;
        while(i>0 &&j>0)
        {
            if(s[i-1]==r[j-1])
            {
                res[ind]=s[i-1];
                ind--;
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
        
    }
    int main()
    {
    	string s;
    	cin>>s;
    	longestPalindrome(s);
    }
