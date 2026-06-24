class Solution {
  private:
    bool solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& ans, int n) {
        if (i == n - 1 && j == n - 1) {
            ans[i][j] = 1;
            return true;
        }
        
        if (i >= n || j >= n || mat[i][j] == 0) {
            return false;
        }
        
        ans[i][j] = 1;
        int jumps = mat[i][j];
        
        for (int k = 1; k <= jumps; k++) {
            if (solve(i, j + k, mat, ans, n)) return true;
            if (solve(i + k, j, mat, ans, n)) return true;
        }
        
        ans[i][j] = 0;
        mat[i][j] = 0;
        
        return false;
    }

  public:
    vector<vector<int>> shortestDist(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        if (solve(0, 0, mat, ans, n)) {
            return ans;
        }
        
        return {{-1}};
    }
};
