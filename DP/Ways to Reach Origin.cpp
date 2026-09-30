class Solution {
  public:
    int ways(int x, int y) {
        // code here
        vector<int>dp(y+1,1);
        int mod = 1e9 + 7;
        
        for(int i=1;i<=x;i++){
            int pre = 1;
            for(int j=1;j<=y;j++){
                dp[j] = (pre+dp[j])%mod;
                pre = dp[j];
            }
        }
        
        return dp[y];
    }
};
