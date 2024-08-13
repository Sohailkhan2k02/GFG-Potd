//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
  public:
  int res=0;
    int f(int i, int j, string &s, string &t,vector<vector<int>>&dp){
        int n=s.size(),m=t.size();
        int ans=0;
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            dp[i][j]=ans=1+f(i+1,j+1,s,t,dp);
            res=max(res,ans);
        }
        dp[i][j]=f(i+1,j,s,t,dp);
        dp[i][j]=f(i,j+1,s,t,dp);
        return dp[i][j]=ans;
    }
    int longestCommonSubstr(string s, string t) {
        // your code here
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        f(0,0,s,t,dp);
        return res;
        
    }
};
