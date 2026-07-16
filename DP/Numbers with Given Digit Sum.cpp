class Solution {
  public:
    int countWays(int n, int sum) {
        // code here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int ans=-1;
        for(int j=1;j<=min(9,sum);j++)
            dp[0][j]=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                for(int k=0;k<=9;k++)
                {
                    if(k+j<=sum && k+j>0 && dp[i-1][j]>=1)
                    {
                        if(dp[i][k+j]==-1)
                            dp[i][k+j]=0;
                        dp[i][k+j]+=dp[i-1][j];
                    }
                }
            
            }
          
        }
        
        ans=dp[n-1][sum];
        
        return ans;
    }
};
