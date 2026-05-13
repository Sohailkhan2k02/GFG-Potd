class Solution {
  public:
    void dfs(int node, vector<int> &vis, vector<int> adj[]){
        vis[node]=1;
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
    }
  public:
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V, 0);
        vector<int> adj[V];
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            adj[u].push_back(v);
        }
        int mother=0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                mother= i;
            }
        }
        fill(vis.begin(), vis.end(), 0);
        //verify kat lo
        dfs(mother, vis, adj);
        for(int i=0; i<V; i++){
            if(!vis[i])return -1;
        }
        return mother;
        
    }
};
