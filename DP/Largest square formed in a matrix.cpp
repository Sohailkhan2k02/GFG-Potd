//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
  public:
    int f(int i, int j, vector<vector<int>>&mat, int n, int m,vector<vector<int>>&dp){
        if(i<0 || i>=n || j<0 || j>=m || mat[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int delrow[]={0,1,1};
        int delcol[]={1,1,0};
        int res=INT_MAX;
        for(int k=0; k<3; k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            
            res=min(res,1+f(nrow,ncol,mat,n,m,dp));
        }
        return dp[i][j]=res;
    }
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int a=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    a=max(a,f(i,j,mat,n,m,dp));
                }
            }
        }
        return a;
    }
};
