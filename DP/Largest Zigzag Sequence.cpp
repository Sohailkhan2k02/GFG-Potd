class Solution {
    vector<vector<int>> dp;
    int solve(int row, int col, int n, vector<vector<int>>& mat) {
        if (row == n - 1) return mat[row][col];
        if (dp[row][col] != -1) return dp[row][col];
        
        int result = 0;
        for (int j = 0; j < n; j++) {
            if (j != col)
                result = max(result, solve(row + 1, j, n, mat));
        }
        
        return dp[row][col] = mat[row][col] + result;
    }
  public:
    int zigzagSequence(vector<vector<int>>& mat) {
        int n = mat.size(), ans = 0;
        dp.resize(n + 1, vector<int>(n + 1, -1));
        
        for (int col = 0; col < n; col++) 
            ans = max(ans, solve(0, col, n, mat));
        
        return ans;
    }
};
