//T.C : O(n*w)
//S.C : O(n*w)
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int f(int i, vector<int>&wt, vector<int>&val, int w, int n,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        int take=0;
        if(w-wt[i]>=0){
            take=val[i]+f(i+1,wt,val,w-wt[i],n,dp);
        }
        int ntake=f(i+1,wt,val,w,n,dp);
        return dp[i][w]=max(take,ntake);
    }
    int knapSack(int w, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=val.size();
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        return f(0,wt,val,w,n,dp);
    }
};
