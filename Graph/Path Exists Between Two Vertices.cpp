class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
        // code here
        int n = adj.size();
                vector<bool> vis(n, false);
                queue<int> q;
                q.push(u);
                vis[u] = true;
                while (!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    if (curr == v) return true;
                    for (int nei : adj[curr]) {
                        if (!vis[nei]) {
                            vis[nei] = true;
                            q.push(nei);
                        }
                    }
                }
                return false;
    }
};
