/*
https://leetcode.com/problems/jump-game-ii/

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

1 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/

class Solution {
public:
	int solve(int ind,vector<int>& nums,int n,vector<int>& dp){
		if(ind==n) return 0;
		if(ind>n) return 1e9;
		
		if(dp[ind]!=-1) return dp[ind];
		
		int temp = 1e9;
		for(int i=1;i<=nums[ind];i++){
			temp = min(temp,1+solve(ind+i,nums,n,dp));
		}
		return dp[ind] = temp;
	}
	int jump(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n,-1);
		return solve(0,nums,n-1,dp);
	}
};
