//T.C : O(n)
//S.C : O(n)
class Solution {
int mod = 1e9+7;
    int f(string &str,int n,vector<int>&dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n]; 
        int cnt=0;
        if(str[n-1] >= '1') cnt = cnt + f(str,n-1,dp)%mod;
        if(str[n-2] =='1' || str[n-2] == '2' && str[n-1] <='6') cnt = (cnt + f(str,n-2,dp)%mod)%mod;
        
        return dp[n] = cnt%mod;
    }
	public:
		int countWays(string str){
		    // Code here
		    int n=str.length();
		    if(str[0]=='0') return 0;
		    vector<int>dp(n+1,-1);
		    
		    return f(str,n,dp);
		}
};
