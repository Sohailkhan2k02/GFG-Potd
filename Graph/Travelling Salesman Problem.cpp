class Solution {
  public:
    int tsp(vector<vector<int>>& cost) 
    {
        int n = cost.size();
        int N = 1<<n;
        int ans = INT_MAX;
        vector<vector<int>> dp(N,vector<int>(n,INT_MAX));
        dp[1][0] = 0;
        
        for(int mask = 0; mask < N; mask++)
        {
            for(int i = 0; i < n; i++)
            {
                if(dp[mask][i] == INT_MAX)
                    continue;
                
                for(int j = 0; j < n; j++)
                {
                    if(mask & (1<<j))
                        continue;
                    int newMask = mask | (1<<j);
                    dp[newMask][j] = min(dp[newMask][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
        
        int fullmask = N-1;
        for(int j = 1; j < n; j++)
        {
            ans = min(ans,dp[fullmask][j] + cost[j][0]);
        }
        return ans==INT_MAX?0:ans;
    } 
};
