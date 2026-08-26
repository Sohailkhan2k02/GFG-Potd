class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> dist(V, 0);

        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] + w < dist[v]) {
                return true;
            }
        }
        
        return false;
    }
};
