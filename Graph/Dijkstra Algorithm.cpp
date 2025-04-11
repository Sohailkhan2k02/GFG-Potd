//T.C : O(Elog(v))
//S.C : O(E+V)
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto& i : edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while(!pq.empty()){
            pair<int, int> curr = pq.top();
            pq.pop();
            int d = curr.first;
            int u = curr.second;

            if(d > dist[u])
                continue;

            for(const auto& neighbor : adj[u]){
                int v = neighbor.first;
                int w = neighbor.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
