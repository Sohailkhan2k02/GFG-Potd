//T.C : O(n * (m + n * log(n)))
//S.C: O(n + m)
class Solution {
  public:
    void DjskstrasAlgo(int src, unordered_map<int, list<pair<int,int>>>& adj, vector<int>& dist) {
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto node = pq.top().second;
            auto nodeDist = pq.top().first;
            pq.pop();
            
            for(auto i: adj[node]) {
                if(i.second + nodeDist < dist[i.first]) {
                    dist[i.first] = nodeDist + i.second;
                    pq.push({dist[i.first], i.first});
                }
            }
        }
        
        return;
    }
  
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        
        unordered_map<int, list<pair<int,int>>> adj;
        for(int i=0; i<m; i++) {
            auto u = edges[i][0];
            auto v = edges[i][1];
            auto w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int minCities = INT_MAX, ans = 0;
        for(int i=0; i<n; i++) {
            vector<int> dist(n, 1e9);
            
            DjskstrasAlgo(i, adj, dist);
            
            int cityCnt = 0;
            for(int j=0; j<n; j++) {
                // cout << dist[j] << " ";
                if(dist[j] <= distanceThreshold && dist[j] != 0) {
                    cityCnt++;
                }
            }
            
            if(cityCnt <= minCities) {
                minCities = cityCnt;
                ans = i;
            }
        }
        
        return ans;
    }
};
