//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
  public:
    // Function to find the number of islands.
    void f(int i, int j, vector<vector<char>>&grid,vector<vector<int>>&vis, int n, int m){
        if(i>=n || i<0 || j>=m || j<0 || grid[i][j]=='0' || vis[i][j]==1) return;
        vis[i][j]=1;
        
        int delrow[]={-1,0,1,0,-1,1,1,-1};
        int delcol[]={0,1,0,-1,1,1,-1,-1};
        for(int k=0; k<8; k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            f(nrow,ncol,grid,vis,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    f(i,j,grid,vis,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
