class Solution {
  public:
  int dx[8]={2,1,-1,-2,-2,-1,1,2};
  int dy[8]={1,2,2,1,-1,-2,-2,-1};
  bool isSafe(int x,int y,int n,vector<vector<int>>&ans){
      return (x>=0 && y>=0&& x<n&& y<n&& ans[x][y]==-1);
  }
  bool solve (vector<vector<int>>&ans,int r ,int c,int val,int n){
       if(val==n*n)return true;
       
       for(int k=0;k<8;k++){
           int nx=r+dx[k];
           int ny=c+dy[k];
           if(isSafe(nx,ny,n,ans)){
               ans[nx][ny]=val;
               if(solve(ans,nx,ny,val+1,n))return true;
               ans[nx][ny]=-1;
           }
       }
       return false;
  }
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>>ans(n,vector<int>(n,-1));
        ans[0][0]=0;
        
        if(!solve(ans,0,0,1,n))return {};
        
        return ans;
    }
};
