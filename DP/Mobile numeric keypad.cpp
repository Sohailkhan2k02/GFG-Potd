//T.C : O(N)
//S.C : O(N)
class Solution {
  public:
  int mat[4][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {-1, 0, -1}
        };
        
    long long f(int i, int j, int n, vector<vector<long long>>&dp){
        if(i<0 || i>=4 || j<0 || j>=3 || mat[i][j]==-1) return 0;
        if(n==1) return 1;
        if(dp[mat[i][j]][n]!=-1) return dp[mat[i][j]][n];
        
        long long a=0;
        a+=f(i,j,n-1,dp);
        long long delrow[]={-1,0,1,0};
        long long delcol[]={0,1,0,-1};
        for(int k=0; k<4; k++){
            long long nrow=i+delrow[k];
            long long ncol=j+delcol[k];
            a+=f(nrow,ncol,n-1,dp);
        }
        return dp[mat[i][j]][n]=a;
    }
    long long getCount(int n) {
        vector<vector<long long>>dp(10,vector<long long>(n+1,-1));
        long long res=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                if(mat[i][j]!=-1){
                    res+=f(i,j,n,dp);
                }
            }
        }
        return res;
    }
};
