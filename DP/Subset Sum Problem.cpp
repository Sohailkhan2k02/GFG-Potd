//T.C : O(n*n)
//S.C : O(n*n)
//User function template for C++

class Solution{   
public:
    bool f(int i, vector<int>&nums, int t, int sum, int n,vector<vector<int>>&dp){
        if(i>=n && sum!=t) return false;
        if(i>=n && sum==t) return true;
        if(dp[i][sum]!=-1) return dp[i][sum];

        int take=0;
        if(sum+nums[i]<=t){
            take=f(i+1,nums,t,sum+nums[i],n,dp);
        }
        int ntake=f(i+1,nums,t,sum,n,dp);
        return dp[i][sum]=take||ntake;
    }
    
    
    bool isSubsetSum(vector<int> nums, int sum){
        // code here 
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return f(0,nums,sum,0,n,dp);
    }
};
