class Solution {
  public:
    const int mod = 1e9+7;
    int totalPaths(int i, int j, vector<vector<int>>& grid, int n, vector<vector<int>>& dp)
    {
        if(i == n-1 && j == n-1)
        {
            return dp[i][j] = 1;
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int ans = 0;
        
        if(grid[i][j] != 2 && j+1<n)
        {
            ans += totalPaths(i, j+1, grid, n, dp);
        }
        
        if(grid[i][j] != 1 && i+1 < n)
        {
            ans += totalPaths(i+1, j, grid, n, dp);
        }
        
        return dp[i][j] = ans % mod;
    }
    
    int maxAdventure(int i, int j, vector<vector<int>>& grid, int n, vector<vector<int>>& dp)
    {
        if (i == n - 1 && j == n - 1) 
        {
            return dp[i][j] = grid[i][j];
        }
    
        if (dp[i][j] != -1) 
        {
            return dp[i][j];
        }
        
        int a = 0;
        int b = 0;
        
        if(grid[i][j] != 2 && j+1<n)
        {
            a = maxAdventure(i, j+1, grid, n, dp);
        }
        
        if(grid[i][j] != 1 && i+1 < n)
        {
            b = maxAdventure(i+1, j, grid, n, dp);
        }
        
        if(a == 0 && b == 0)
        {
            return dp[i][j] = 0;
        }
        
        return dp[i][j] = max(a,b) + grid[i][j];
    }
  
    vector<int> findWays(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int paths = totalPaths(0,0,grid, n, dp);
        
        for (auto &row : dp) {
            fill(row.begin(), row.end(), -1);
        }
        
        int maxAdv = maxAdventure(0, 0, grid, n, dp);
        
        return {paths, maxAdv};
    }
};
