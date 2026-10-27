class Solution {
  public:
    int getMaxWeight(string &s) {
        // code here
        int n = s.size();
                vector<int> dp(n + 1);

                dp[0] = 0;
                dp[1] = 1;

                for (int i = 2; i <= n; i++) {
                    dp[i] = dp[i - 1] + 1;

                    int pair = (s[i - 2] != s[i - 1]) ? 4 : 3;
                    dp[i] = max(dp[i], dp[i - 2] + pair);
                }

                return dp[n];
    }
};
