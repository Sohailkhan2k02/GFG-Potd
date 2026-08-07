class Solution {
  public:
  const int mod = 1e9+7;
    long long f(int i, vector<long long>&dp){
        if(i==1 || i==2){
            return i;
        }
        if(dp[i]!=-1) return dp[i];
        long long take = f(i-1,dp)%mod;
        long long nottake = ((i-1)*(f(i-2,dp)%mod))%mod;
        
        return dp[i] = (take+nottake)%mod;
    }
    int countFriendsPairings(int n) {
        // code here
        vector<long long> dp(n+1, -1);
        return f(n, dp);
    }
};
