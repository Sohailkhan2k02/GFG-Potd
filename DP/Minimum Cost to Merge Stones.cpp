class Solution {
  public:
    int mergeStones(vector<int> &stones, int k) {
        // code here
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) 
            prefix[i + 1] = prefix[i] + stones[i];
        auto getSum = [&](int l, int r) {
            return prefix[r + 1] - prefix[l];
        };
        const int INF = 1e9;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(k + 1, INF))
        );
        for (int i = 0; i < n; i++)
            dp[i][i][1] = 0;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int t = 2; t <= k; t++) {
                    dp[i][j][t] = INF;
                    for (int mid = i; mid < j; mid += (k - 1)) {
                        if (dp[i][mid][1] == INF || dp[mid+1][j][t-1] == INF)
                            continue;
                        dp[i][j][t] = min(dp[i][j][t], 
                                          dp[i][mid][1] + dp[mid+1][j][t-1]);
                    }
                }
                if (dp[i][j][k] < INF)
                    dp[i][j][1] = dp[i][j][k] + getSum(i, j);
            }
        }
        return dp[0][n-1][1];
    }
};
