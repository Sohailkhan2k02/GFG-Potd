//T.C : O(n*n)
//S.C : O(1)
// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
          int n = dist.size();
    int INF = 1e8;

    // Update diagonal
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][via] < INF && dist[via][j] < INF) {
                    // Cast to long long to avoid overflow
                    int newDist = dist[i][via] + dist[via][j];
                    if (newDist < dist[i][j]) dist[i][j] = newDist;
                }
            }
        }
        }
    }
};
