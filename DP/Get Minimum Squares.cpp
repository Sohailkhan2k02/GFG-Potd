class Solution {
  public:
    int solve(int n, vector<int>& dp){
        if(n==0) return 0;
        // if(n<0) return INT_MAX;
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;
        
        for(int i = 1;i<=sqrt(n);i++){
            int sq = i*i;
            ans = min(ans, 1 + solve(n-sq, dp));
        }
        
        return dp[n] = ans;
    }
    int minSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
