// User function Template for C++

class Solution{
public:
    void dfs(int i, int j, vector<vector<char>>&mat, vector<vector<int>>&vis){
        int n=mat.size(),m=mat[0].size();
        if(i<0 || i>=n || j<0 || j>=m || mat[i][j]=='X' || vis[i][j]==1){
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
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code herem
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0; j<m; j++){
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,mat,vis);
            }
            
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,mat,vis);
            }
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,mat,vis);
            }
            
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,mat,vis);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};
