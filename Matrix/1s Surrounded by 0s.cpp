// User function Template for C++

class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>>&mat, vector<vector<int>>&vis){
        int n=mat.size(),m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m || mat[i][j]==0 || vis[i][j]==1){
            return;
        }

        vis[i][j]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int k=0; k<4; k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];

            dfs(nrow,ncol,mat,vis);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0; j<m; j++){
            if(!vis[0][j] && mat[0][j]==1){
                dfs(0,j,mat,vis);
            }

            if(!vis[n-1][j] && mat[n-1][j]==1){
                dfs(n-1,j,mat,vis);
            }
        }

        for(int i=0; i<n; i++){
            if(!vis[i][0] && mat[i][0]){
                dfs(i,0,mat,vis);
            }

            if(!vis[i][m-1] && mat[i][m-1]){
                dfs(i,m-1,mat,vis);
            }
        }

        int len=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j]==1){
                    // dfs1(i,j,mat,vis,len);
                    len++;
                }
            }
        }
        return len;
    }
};
