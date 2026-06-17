class Solution {
  public:
    virtual int svc(int n, vector<int> &dp){
      if(n<=2) return 1;
      
      if(dp[n]!=-1) return dp[n];
      
      int ans=INT_MIN;
      for(int k=1; k<n; k++){
        int t=k*svc(n-k, dp);
        ans=max(t, ans);
        ans=max(k*(n-k), ans);
      }
      
      return dp[n]=ans;
    }
  
    virtual int maxProduct(int n){
      vector<int> dp(n+1, -1);    
      return svc(n, dp);
    }
};
