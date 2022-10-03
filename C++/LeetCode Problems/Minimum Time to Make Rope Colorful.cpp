class Solution{
  int minCost(string s, vector<int>& cost) {
      int res = cost[0], maxCost = cost[0];
      for (int i = 1; i < s.size(); ++i) {
          if (s[i] != s[i - 1]) {
              res -= maxCost;
              maxCost = 0;
          }
          res += cost[i];
          maxCost = max(maxCost, cost[i]);
      }
      return res - maxCost;
  }
};
