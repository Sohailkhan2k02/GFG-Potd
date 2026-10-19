class Solution {
  public:
    int goodIndices(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            int dest=i+arr[i];
            if(dest<0 || dest>=n) q.push(i);
            else adj[i+arr[i]].push_back(i);
            
        }
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            vis[idx]=1;
            for(auto it:adj[idx]){
                q.push(it);
            }
        }
        return accumulate(vis.begin(),vis.end(),0);
    }
};
