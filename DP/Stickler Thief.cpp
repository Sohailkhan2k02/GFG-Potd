//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int sum(int i,vector<int>&arr,vector<int> &dp){
        if(i<0) return 0;
        if(i == 0) return arr[i];
        
        if(dp[i] != -1) return dp[i];
        
        int take = arr[i] + sum(i-2,arr,dp);
        int nottake = sum(i-1, arr, dp);
        return dp[i] = max(take, nottake);

    }
    
    int findMaxSum(vector<int>&arr)
    {
        int n=arr.size();
        vector<int> dp(n,-1);
        return sum(n-1,arr,dp);
    }
};
