//T.C : O(n*w)
//S.C : O(n*w)
class Solution {
  public:
    int f(int i,vector<int>cost, int n, int w,vector<vector<int>>&dp){
	    if(i>=n){
	        if(w==0) return 0;
	        else return 1e9;
	    }
	    if(w<0) return 1e9;
	    if(dp[i][w]!=-1) return dp[i][w];
	    int take=0,nottake=0;
	    if(cost[i]!=-1){
	        take+=cost[i]+f(i,cost,n,w-(i+1),dp);
	    }
	    nottake=f(i+1,cost,n,w,dp);
	    return dp[i][w]=min(take,nottake);
	}
	int minimumCost(int n, int w, vector<int>&cost){ 
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        int ans= f(0,cost,n,w,dp);
        return ans;
	}
};
