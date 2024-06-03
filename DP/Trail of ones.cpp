//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int mod=1e9+7;

    long long power(long long a,long long b){
        long long ans=1;
        while(b){
            if(b%2)ans*=a;
            b>>=1;
            a*=a;
            a%=mod;
            ans%=mod;
        }
        return ans;
    }
    long long solve(int n,vector<int> &dp){
        if(n==2) return 1;
        if(n==3) return 3;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=((solve(n-1,dp) + power(2,n-2))%mod+ solve(n-2,dp))%mod;
    }
    int numberOfConsecutiveOnes(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
