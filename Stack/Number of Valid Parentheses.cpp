class Solution {
  public:
    int findWays(int n) {
        // code here
        if(n % 2 != 0){
            return 0;
        }
        vector<vector<int>>dp(n, vector<int>((n/2)+1,0));
        
        // base case
        dp[n-1][0] = 1;
     
        for(int index = n-2; index>=0; index--){
            for(int openCount = 0; openCount <= n/2; openCount++){
                int count = 0;
                if(openCount < n/2) count += dp[index+1][openCount+1];
                if(openCount > 0) count += dp[index+1][openCount-1];
                
                dp[index][openCount] = count;
            }
        }
        
        return dp[0][1];
    }
};
