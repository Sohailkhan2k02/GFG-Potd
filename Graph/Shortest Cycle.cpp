class Solution {
  public:
    void dfs(int node ,vector<vector<int>>&adj , vector<int>& vis , int prev , int &ans){
        vis[node] = prev;
        for(auto i: adj[node]){
            if(vis[i] == 0)dfs(i , adj , vis , prev+1 , ans);
            else if(vis[node] - vis[i] >1){
                if(ans ==-1)ans = vis[node] - vis[i] +1;
                else ans = min (ans , vis[node] - vis[i] +1);
            }
            else if(vis[node] +1 < vis[i] )dfs(i , adj , vis , prev+1 ,ans );
        }
  }
    int shortCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int ans = -1;
        vector<vector<int>>adj(V);
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(V , 0);
        for(int i=0;i<V;i++){
            if(vis[i]==0 && adj.size()>0)dfs(i, adj , vis, 1, ans);
        }
        return ans;
        
    }
};
