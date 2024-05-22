//T.C : O(n*n)
//S.C : O(n*n)
class Solution{
public:
    int f(int i, int j,string &s, int n, int k, vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==s[j]){
            return dp[i][j]=f(i+1,j-1,s,n,k,dp);
        }
        else{
            return dp[i][j]=1+min(f(i+1,j,s,n,k,dp),f(i,j-1,s,n,k,dp));
        }
    }
    int kPalindrome(string s, int n, int k)
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int res=f(0,n-1,s,n,k,dp);
        if(res<=k) return true;
        return false;
    }
};
