class Solution {
  public:
    int mod = 1e9 + 7;

    vector<vector<vector<int>>> dp;

    int solve(int n, int k, int sz, char prev, int count) {
        if (sz >= n)
            return (count == k);

        if (prev == 0)
            return (solve(n, k, sz + 1, '0', count) +
                    solve(n, k, sz + 1, '1', count)) %
                   mod;

        if (dp[sz][prev - '0'][count] != -1)
            return dp[sz][prev - '0'][count];

        if (prev == '0')
            return dp[sz][prev - '0'][count] =
                       (solve(n, k, sz + 1, '0', count) +
                        solve(n, k, sz + 1, '1', count)) %
                       mod;

        return dp[sz][prev - '0'][count] =
                   (solve(n, k, sz + 1, '0', count) +
                    solve(n, k, sz + 1, '1', count + 1)) %
                   mod;
    }

    int countStrings(int n, int k) {
        dp = vector<vector<vector<int>>>(
            n, vector<vector<int>>(2, vector<int>(n, -1)));
        return solve(n, k, 0, 0, 0);
    }
};
