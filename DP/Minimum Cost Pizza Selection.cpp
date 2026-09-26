class Solution {
  public:
    int solve(int x, int s, int m, int l, int cs, int cm, int cl, vector<int>& dp) {
        
        
        if (x  <= 0) return 0;
        
        if (dp[x] != -1) {
            return dp[x];
        }
        
        int small =  cs + solve(x - s, s, m, l, cs, cm, cl, dp);
        int medium = cm + solve(x - m, s, m, l, cs, cm, cl, dp);
        int large =  cl + solve(x - l, s, m, l, cs, cm, cl, dp);
        
        return dp[x] = min({small, medium, large});
    }
    int minimumCost(int X, int s, int m, int l, int cs, int cm, int cl) {
        // code here
        
        // vector<int> dp(X+2, -1);
        // return solve(x, s, m, l, cs, cm, cl, dp);
        
        vector<int> dp(X+2, 0);
        
        for (int x = 1; x <= X; x++) {
            
            int small = cs + (x - s >= 0 ? dp[x - s] : 0);
            int medium = cm +(x - m >= 0 ? dp[x - m] : 0);
            int large = cl + (x - l >= 0 ? dp[x - l] : 0);
            
            dp[x] = min({small, medium, large});
        }
        
        return dp[X];
    }
};
