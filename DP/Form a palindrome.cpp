//T.C : O(n*n)
//S.C : O(n*n)
class Solution{
  public:
    int f(int i, int j, string &s1, string &s2,vector<vector<int>>&dp){
        int n=s1.size();
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0,nottake=0;
        if(s1[i]==s2[j]){
            dp[i][j]=take=1+f(i+1,j+1,s1,s2,dp);
        }
        else dp[i][j]=nottake=max(f(i+1,j,s1,s2,dp),f(i,j+1,s1,s2,dp));
    }
    int countMin(string s){
    //complete the function here
        int n=s.size();
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int l=f(0,0,s,t,dp);
        return n-l;
    }
};
