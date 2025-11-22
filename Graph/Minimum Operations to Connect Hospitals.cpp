
    class Solution {
    
    void dfs(int u, int &edges, int &vertices, vector<int> &vis, vector<vector<int>> &adj) {
        vis[u] = 1;
        edges += adj[u].size();
        vertices++;
        
        for(int v : adj[u]) {
            if(!vis[v]) {
                dfs(v, edges, vertices, vis, adj);
            }
        }
    }
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        int extraEdges = 0;
        int numComponents = 0;
        
        vector<vector<int>> adj(V);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                int edges = 0;
                int vertices = 0;
                
                dfs(i, edges, vertices, vis, adj);
                
                edges /= 2;
                int mnReqEdgesInComponent = vertices - 1;
                extraEdges += (edges - mnReqEdgesInComponent);
                numComponents ++;
            }
        }
        
        int edgesRequiredToConnect = numComponents - 1;
        if(extraEdges < edgesRequiredToConnect) return -1;
        
        return edgesRequiredToConnect;
        
    }
};
