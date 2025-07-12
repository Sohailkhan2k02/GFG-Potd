class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        int res = 0;
        int left, diagonal_up, diagonal_down;

        for (int j = 1; j < m; j++) {

            for (int i = 0; i < n; i++) {
                
                left = mat[i][j - 1];
                diagonal_up = diagonal_down = 0;
                
                if (i > 0)  
                    diagonal_up = mat[i - 1][j - 1];
                
                if (i < n - 1)
                    diagonal_down = mat[i + 1][j - 1];
                
                mat[i][j] += max({left, diagonal_up, diagonal_down});
            }

        }
            
        for (int i = 0; i < n; i++) {
            res = max(res, mat[i][m - 1]);
        }
        return res;
        
    }
};
