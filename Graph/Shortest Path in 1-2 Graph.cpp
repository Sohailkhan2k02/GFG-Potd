class Solution {
  public:
    typedef pair<int, int> P;
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<P>> adj;
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> path(V, INT_MAX);
        
        for (auto& edge : edges) {
            
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        path[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            
            auto [d, node] = pq.top();
            pq.pop();
            
            if (node == dest) {
                return d;
            }
            
            for (auto ngbr : adj[node]) {
                int v = ngbr.first;
                int w = ngbr.second;
                
                if (path[v] > d + w) {
                    path[v] = d + w;
                    pq.push({d+w, v});
                }
            }
        }
        
        return -1;
    }
};
