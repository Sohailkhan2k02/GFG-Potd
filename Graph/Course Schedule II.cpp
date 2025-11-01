class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0){
                q.push(i);
            }
        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            for (auto next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        if (order.size() == n) 
            return order;
        return {};
    }
};
