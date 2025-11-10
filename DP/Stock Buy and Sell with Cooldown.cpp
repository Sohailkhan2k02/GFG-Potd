class Solution {
  public:
    using ll=int;
    vector<vector<ll>> dp;
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp=vector<vector<ll>>(n+2,vector<ll>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j) dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else dp[i][j]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
            }
        }

        return dp[0][1];
    }
};
