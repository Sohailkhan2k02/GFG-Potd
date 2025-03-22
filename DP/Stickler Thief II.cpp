//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int fun(int i, int take, int &n, vector<int> &a, vector<vector<int>> &dp){
        if(i>=n || (i==n-1 && take))
            return 0;
        
        if(dp[i][take] != -1)
            return dp[i][take];
        
        int t = 0;
        if(i==0)
            t= a[i] + fun(i+2, 1, n, a, dp);
        else
            t = a[i] + fun(i+2, take, n, a, dp);
        
        int nt = fun(i+1, take, n, a, dp);
        
        return dp[i][take] = max(t, nt);
        
    }
  
    int maxValue(vector<int>& arr) {
        // your code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        
        return fun(0, 0, n, arr, dp);
    }
};
