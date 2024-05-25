//T.C : O(n*m)
//S.C : O(n*m)
class Solution {

  public:
    int f(int i, int j,string &x, string &y,vector<vector<int>>&dp){
        int n=x.size(),m=y.size();
        if(i>=n || j>=m){
            return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(x[i]==y[j]){
            return dp[i][j]=1+f(i+1,j+1,x,y,dp);
        }
        else{
            return dp[i][j]=max(f(i+1,j,x,y,dp),f(i,j+1,x,y,dp));
        }
    }
    int findMinCost(string x, string y, int cx, int cy) {
        // Your code goes here
        int n=x.size(),m=y.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int len= f(0,0,x,y,dp);
        n-=len,m-=len;
        return (n*cx+m*cy);
    }
};
