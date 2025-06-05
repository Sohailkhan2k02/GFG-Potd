class Solution {
  public:
  int dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& dp) {
    if (node == dest) return 1;
    if (dp[node] != -1) return dp[node];

    int totalPaths = 0;
    for (int neighbor : adj[node]) {
        totalPaths += dfs(neighbor, dest, adj, dp);
    }
    return dp[node] = totalPaths;
}

int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
    vector<vector<int>> adj(V);
    
    // Build adjacency list
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<int> dp(V, -1);  // Memoization array
    return dfs(src, dest, adj, dp);
}
    };
