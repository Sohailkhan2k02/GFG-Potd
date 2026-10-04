class Solution {
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();

        long long peri = 0;                     
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] != 1) continue;    
                peri += 4;                       
                if (i + 1 < n && mat[i + 1][j] == 1) peri -= 2;                  
                if (j + 1 < m && mat[i][j + 1] == 1) peri -= 2;
            }
        }
        return static_cast<int>(peri);  
    }
};
