class Solution {
  public:
      int solve(int i, int incIdx, int decIdx, vector<int>& arr, vector<vector<vector<int>>>& dp) {
        
        if (i == arr.size()) {
            return 0;
        }
        
        if (dp[i][incIdx+1][decIdx+1] != -1) {
            return dp[i][incIdx+1][decIdx+1];
        }
        int skip = solve(i+1, incIdx, decIdx, arr, dp);
        int ans = 0;
        
        if (incIdx == -1 || arr[incIdx] < arr[i]) {
            ans= max(ans, 1 + solve(i+1, i, decIdx, arr, dp));
        }
        
        
        if (decIdx == -1 || arr[decIdx] > arr[i]) {
            ans = max(ans, 1 + solve(i+1, incIdx, i, arr, dp));
        }
        
    
        return dp[i][incIdx+1][decIdx+1] = max(ans, skip);
    }
    int minCount(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        vector dp(n+1, vector(n+1, vector<int>(n+1, -1)));
        int ans = solve(0, -1, -1, arr, dp);
        
        return n - ans;
    }
};
