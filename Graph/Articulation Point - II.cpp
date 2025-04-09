//T.C : O(V*E)
//S.C : O(V)
class Solution {
  public:
    void dfs(int u, int parent, vector<int>& disc, vector<int>& low, vector<bool>& visited, set<int>& articulationPoints, vector<vector<int>>& adj, int& time) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;
        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                dfs(v, u, disc, low, visited, articulationPoints, adj, time);
                
                // Check if the subtree rooted at v has a connection back to one of the ancestors of u
                low[u] = min(low[u], low[v]);

                // u is an articulation point if the lowest vertex reachable from subtree under v is below u in DFS tree
                if (low[v] >= disc[u] && parent != -1) {
                    articulationPoints.insert(u);
                }
            } else if (v != parent) { // Update low value of u for parent function calls
                low[u] = min(low[u], disc[v]);
            }
        }

        // If u is root of DFS tree and has two or more children
        if (parent == -1 && children > 1) {
            articulationPoints.insert(u);
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false);
        set<int> articulationPoints;
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, disc, low, visited, articulationPoints, adj, time);
            }
        }

        vector<int> result(articulationPoints.begin(), articulationPoints.end());
        if (result.empty()) {
            return {-1};
        }
        return result;
    }
};
