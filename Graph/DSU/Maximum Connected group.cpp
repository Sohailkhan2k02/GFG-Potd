//T.C : O(n*n)
//S.C : O(n*n)
class DisJointSet{
public:
  vector<int>parent,size;
  DisJointSet(int n){
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
     parent[i]=i;
     size[i]=1;
    }
  }
   int findUPar(int node){
      if(node==parent[node]){
          return node;
     }
    return parent[node]=findUPar(parent[node]);
  }
   void unionBySize(int u,int v){
      int ultimateParent_u=findUPar(u);
      int ultumateParent_v=findUPar(v);
    
   if(ultimateParent_u==ultumateParent_v){
       return;
    }
   if(size[ultimateParent_u]<size[ultumateParent_v]){
      parent[ultimateParent_u]=ultumateParent_v;
      size[ultumateParent_v]+=size[ultimateParent_u];
    }else{
      parent[ultumateParent_v]=ultimateParent_u;
      size[ultimateParent_u]+=size[ultumateParent_v];
    }

}

};
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        
         int n=grid.size();
         int m=grid[0].size();
         DisJointSet ds=DisJointSet(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==0) continue;
                  
             int row[]={1,0,-1,0};
             int col[]={0,-1,0,1};
               for(int ii=0;ii<4;ii++){
                  int nrow=i+row[ii];
                  int ncol=j+col[ii];
                  int rowcolnumber=nrow*m+ncol;
                  int nrowcolnumber=i*m+j;
                  
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                ds.unionBySize(rowcolnumber,nrowcolnumber);
                      }
                  }
            }
        }
        int ANS=0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1) continue;
                  
                  int row[]={1,0,-1,0};
                  int col[]={0,-1,0,1};
                  set<int>component;

                  for(int ii=0;ii<4;ii++){
                      int nrow=i+row[ii];
                      int ncol=j+col[ii];
                      
                      if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                          int nrowcol=nrow*m+ncol;
                          if(grid[nrow][ncol]==1){
                             component.insert(ds.findUPar(nrowcol));
                          }
                      }
                  }
                  int sum=0;
                  for(auto k:component){
                       sum+=ds.size[k];
                  }
                  ANS=max(ANS,sum+1);
            }
        }
        for(int i=0;i<n*m;i++){
            ANS=max(ANS,ds.size[ds.findUPar(i)]);
        }
       return ANS;
    }
};
