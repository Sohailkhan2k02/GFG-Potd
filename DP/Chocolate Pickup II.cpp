class Solution {
  public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size();
        if (mat[0][0] == -1 || mat[n - 1][n - 1] == -1)
            return 0;

        // 3D DP: dp[k][i1][i2] = max chocolates collected when
        // both paths take k steps and are at (i1, j1) and (i2, j2) respectively.
        vector<vector<vector<int>>> dp(2 * n - 1, 
            vector<vector<int>>(n, vector<int>(n, -1e9)));

        dp[0][0][0] = mat[0][0];  // starting cell

        for (int k = 1; k < 2 * n - 1; k++) {
            for (int i1 = 0; i1 < n; i1++) {
                for (int i2 = 0; i2 < n; i2++) {
                    int j1 = k - i1;
                    int j2 = k - i2;

                    // Check valid positions
                    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) continue;
                    if (mat[i1][j1] == -1 || mat[i2][j2] == -1) continue;

                    // Collect current chocolates
                    int chocolates = mat[i1][j1];
                    if (i1 != i2) chocolates += mat[i2][j2];

                    int bestPrev = -1e9;

                    // 4 possible transitions (both move down or right)
                    if (i1 > 0 && i2 > 0) bestPrev = max(bestPrev, dp[k - 1][i1 - 1][i2 - 1]);
                    if (i1 > 0 && j2 > 0) bestPrev = max(bestPrev, dp[k - 1][i1 - 1][i2]);
                    if (j1 > 0 && i2 > 0) bestPrev = max(bestPrev, dp[k - 1][i1][i2 - 1]);
                    if (j1 > 0 && j2 > 0) bestPrev = max(bestPrev, dp[k - 1][i1][i2]);

                    // Update DP if a valid path exists
                    if (bestPrev != -1e9)
                        dp[k][i1][i2] = bestPrev + chocolates;
                }
            }
        }

        return max(0, dp[2 * n - 2][n - 1][n - 1]);
    }
};
