class Solution {
  public:
  int mod = 1e9 + 7;
    int countSubsequences(string& s, int n) {
        // code here
        int len = s.length();
        // vector<vector<int>>dp (len+1, vector<int>(n+1, -1));
        vector<vector<int>> dp(len+1, vector<int>(n+1, 0));
        vector<int> prev(len+1, 0);
        vector<int> curr(n+1, 0);
        dp[len][0] = 1;
        
     
        for (int i = len-1; i >= 0; i--) {
            
            for (int rem = 0; rem < n; rem++) {
                
                int skip = dp[i+1][rem];
                int num = s[i] - '0';
                int newRem = (rem * 10 + num) % n;
                
                int take = dp[i+1][newRem];
                
                dp[i][rem] = (take + skip) % mod;
            }
        }
        
        return dp[0][0] - 1;
    }
};
