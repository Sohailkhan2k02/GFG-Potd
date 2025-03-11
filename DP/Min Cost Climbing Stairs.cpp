//T.C : O(n)
//S.C : O(n)
//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i<=n;i++)
        {
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        int ans = dp[n];
        return ans;
    }
};
