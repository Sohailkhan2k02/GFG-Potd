//T.C: O(n)
//S.C: O(n)
class Solution {
  public:
    const int m=1e9+7;
    vector<int> Series(int n) {
        // Code here
       vector<int>dp(n+1,0);
       dp[0]=0;
       dp[1]=1;
       for(int i=2; i<=n; i++){
           dp[i]=(dp[i-1]+dp[i-2])%m;
       }
       return dp;
    }
};
