//T.C : O(v+e)
//S.C : O(v+e)
class Solution {
  public: 
    void dfs(int node,vector<int>adj[],int c, int d,vector<int>&vis){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it] && !(node==c && it==d)){
                dfs(it,adj,c,d,vis);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {

        vector<int>adj[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        dfs(c,adj,c,d,vis);
        if(vis[d]) return false;
        return true;
    }
};
