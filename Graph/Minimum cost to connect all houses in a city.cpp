//T.C: O(n*n)
//S.C : O(n)
class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
    int n = houses.size();
    vector<int> minDist(n, INT_MAX);
    vector<bool> inMST(n, false);
    
    minDist[0] = 0; // start from node 0
    int cost = 0;
    
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j) {
            if (!inMST[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        inMST[u] = true;
        cost += minDist[u];

        for (int v = 0; v < n; ++v) {
            if (!inMST[v]) {
                int d = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                minDist[v] = min(minDist[v], d);
            }
        }
    }
    
    return cost;
}
};
