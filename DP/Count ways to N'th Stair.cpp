//APPRAOCH -1 //
//T.C : O(1)
//S.C : O(1)
class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        return (long)n/2 +1;
    }
};


//APPROACH 2 //
//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long f(int n, vector<long long>& dp) {
        if (n == 0 || n==1 ) {
            return 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = f(n - 1, dp) + f(n - 2, dp);
    }

long long countWays(int n) {
    if(n<=1) return 1;
    vector<long long> dp(n + 1, 0);
    // dp[0]=dp[1]=1;
    // return f(n, dp);
    dp[0]=dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=min(dp[i-1],dp[i-2])+1;
    }
    return dp[n];
}
};
