class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        vector<int> dp(n + 1, 0);

        dp[0] = 0;

        for (int x = 1; x <= n; x++) {
            dp[x] = dp[x - 1] + i;

            if (x % 2 == 0) {
                dp[x] = min(dp[x], dp[x / 2] + c);
            } else {
                dp[x] = min(dp[x], dp[x / 2] + c + i);

                dp[x] = min(dp[x], dp[x / 2 + 1] + c + d);
            }
        }

        return dp[n];
    }
};
