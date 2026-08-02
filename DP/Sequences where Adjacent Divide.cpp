class Solution {
  public:
    bool ispossible(int i,int prev){
      
           
        if(prev%i==0 || i%prev==0)
           return true;
           
        return false;
    }
    int solve(int n,int m,int index,int prev, vector<vector<int>>&dp){
        
        if(index>=n)
           return 1;
           
        if(dp[index][prev]!=-1)
            return dp[index][prev];
           
        int ans=0;
        
        for(int i=1;i<=m;i++){
            if(ispossible(i,prev))
            ans+=solve(n,m,index+1,i,dp);
        }
        
        return dp[index][prev]=ans;
    }
    int count(int n, int m) {
        // code here
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,0,1,dp);
    }
};
