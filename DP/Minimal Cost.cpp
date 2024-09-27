//T.C : O(n*k)
//S.C : O(n)
class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n && j-i<k+1; j++){
                dp[j]=min(dp[j],dp[i]+abs(arr[i]-arr[j]));
            }
        }
        return dp[n-1];
    }
};
