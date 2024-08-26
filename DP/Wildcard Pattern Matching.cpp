//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
  public:
    bool f(int i, int j, string &pat, string &str, int n, int m,vector<vector<int>>&dp){
        if(i>=n && j<m){
            return 0;
        }
        if(i>=n && j>=m) return 1;
        if(j>=m){
            while(i<n && pat[i]=='*') i++;
            return i==n;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool match=0;
        if(pat[i]=='?' || pat[i]==str[j]){
           match=f(i+1,j+1,pat,str,n,m,dp);
        }
        bool star=0;
        if(pat[i]=='*'){
            star=max(f(i+1,j,pat,str,n,m,dp),f(i,j+1,pat,str,n,m,dp));
        }
        return dp[i][j]=match||star;
    }
    int wildCard(string pat, string str) {
        // code here
        int n=pat.size(),m=str.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,pat,str,n,m,dp);
    }
};
