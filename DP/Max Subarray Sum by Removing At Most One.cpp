class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
       if(n == 1) return arr[0];
       vector<vector<int>>dp(n,vector<int>(2,INT_MIN));
       dp[0][0] = arr[0];
       dp[1][1] = max(dp[0][0],arr[1]);
       dp[1][0] = max({arr[1] + dp[0][0] , arr[1]});
       int ans =  max({dp[0][0], dp[0][1],dp[1][0],dp[1][1]});
       for(int i=2;i<n;i++){
           dp[i][0] = max(dp[i-1][0] + arr[i] , arr[i]);
           dp[i][1] = max(dp[i-1][0],dp[i-1][1] + arr[i]);
           ans = max({dp[i][0],dp[i][1],ans});
       }
       return ans;
    }
};
