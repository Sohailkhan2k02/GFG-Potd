class Solution {
  public:
    void path(int i,int n,vector<int> &ds,vector<int> &vis,vector<vector<int>> &ans,vector<int>& arr){
      if(ds.size()==n){
          ans.push_back(ds);
          return;
      }
      
      for(int i=0;i<n;i++){
          if(!vis[i]){
              vis[i]=1;
              ds.push_back(arr[i]);
              path(i+1,n,ds,vis,ans,arr);
              vis[i]=0;
              ds.pop_back();
          }
      }
      
  }

  
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> vis(n,0);
        vector<int> ds;
        vector<vector<int>> ans;
        
        path(0,n,ds,vis,ans,arr);
        return ans;
    }
};
