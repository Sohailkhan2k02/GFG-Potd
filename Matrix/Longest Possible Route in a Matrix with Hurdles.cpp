class Solution {
  public:
  int n;
    int m;
    int ans;
    int row[4] = {0,0,-1,1};
    int col[4] = {-1,1,0,0};
    
    bool check(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    void find(int i,int j,int &d1,int &d2,vector<vector<int>>& mat,vector<vector<int>>& path,int &count){
        
        if(i==d1 && j==d2){
            ans =  max(ans,count);
            return;
        }
        
        
        path[i][j] = 1;
        
        for(int k=0;k<4;k++){
            
            
            int ni = i+row[k];
            int nj = j+col[k];
            
            if(check(ni,nj) && mat[ni][nj] && !path[ni][nj]){
                count++;
                find(ni,nj,d1,d2,mat,path,count);
                count--;
            }
            
        }
        
        path[i][j]=0;
        
    }
    
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        n = mat.size();
        m = mat[0].size();
        ans = -1;
        vector<vector<int>>path(n,vector<int>(m,0));
        int count = 0;
        find(xs,ys,xd,yd,mat,path,count);
        
        return ans;
        
    }
};
