//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
  public:
    const int mod = 1e9+7;
    int solve(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target < 0)
            return 0;
        if(idx < 0)
            return target == 0;
        if(dp[idx][target] != -1)
            return dp[idx][target];
        int take = 0, notake = 0;
        if(arr[idx] <= target)
            take = solve(idx - 1, target - arr[idx], arr, dp) % mod;
        notake = solve(idx - 1, target, arr, dp) % mod;
        return dp[idx][target] = (take + notake) % mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if((total + d) & 1)
            return 0;
        int target = ((total + d) / 2) % mod;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, arr, dp);
    }
};
