//T.C : O(n*x)
//S.C : O(n*x)
class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>>dp(n+ 1,vector<int>(x+1, 0));
        dp[0][0]=1; 
        for(int i=1;i<=n;++i){
            for(int j=1;j<=x;++j){
                for(int k=1;k<=m;++k){
                    if(j-k>= 0)
                        dp[i][j]+=dp[i-1][j-k];
                }
            }
        }
        return dp[n][x];
    }
};
