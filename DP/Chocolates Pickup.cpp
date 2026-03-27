class Solution {
  public:
    int n, m;

    int maxChocolate(vector<vector<int>>& grid) {  
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(m, 0));

        // Base case
        for(int j1 = 0; j1 < m; j1++) {
            for(int j2 = 0; j2 < m; j2++) {
                if(j1 == j2)
                    dp[j1][j2] = grid[n-1][j1];
                else
                    dp[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        // Bottom-up
        for(int i = n - 2; i >= 0; i--) {
            vector<vector<int>> temp(m, vector<int>(m, 0));

            for(int j1 = 0; j1 < m; j1++) {
                for(int j2 = 0; j2 < m; j2++) {

                    int maxi = 0;

                    for(int dj1 = -1; dj1 <= 1; dj1++) {
                        for(int dj2 = -1; dj2 <= 1; dj2++) {

                            int nj1 = j1 + dj1;
                            int nj2 = j2 + dj2;

                            if(nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m) {

                                int value;
                                if(j1 == j2)
                                    value = grid[i][j1];
                                else
                                    value = grid[i][j1] + grid[i][j2];

                                value += dp[nj1][nj2];
                                maxi = max(maxi, value);
                            }
                        }
                    }

                    temp[j1][j2] = maxi;
                }
            }

            dp = temp;
        }

        return dp[0][m-1];
    }
};
