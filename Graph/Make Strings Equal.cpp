class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        
        int sz = s.size();
        int tz = t.size();
        
        if (sz!=tz) return -1;
        
        // tCost[i][j] = Cost of transformation from i to j
        vector<vector<int>> tCost(26, vector<int>(26, INT_MAX));
        for (int i=0; i<26; i++) tCost[i][i] = 0;
        
        for (int i=0; i<transform.size(); i++) {
            int u = transform[i][0]-'a';
            int v = transform[i][1]-'a';
            
            tCost[u][v] = min(tCost[u][v], cost[i]);
        }
        
        // minimize each transformation cost (Floyd-Warshall algorithm)
        for (int k=0; k<26; k++) {  // k denotes intermediate node to reach j from i
            for (int i=0; i<26; i++) {
                for (int j=0; j<26; j++) {
                    if (tCost[i][k]!=INT_MAX && tCost[k][j]!=INT_MAX) {
                        tCost[i][j] = min(tCost[i][j], tCost[i][k]+tCost[k][j]);
                    }
                }
            }
        }
        
        int ans=0;
        
        for (int i=0; i<sz; i++) {
            if (s[i]==t[i]) continue;
            int a = s[i]-'a';
            int b = t[i]-'a';
            
            int c1 = tCost[a][b];
            int c2 = tCost[b][a];
            
            int c3 = INT_MAX/2;
            for (int x=0; x<26; x++) {  // converting to some character x
                if (tCost[a][x]!=INT_MAX && tCost[b][x]!=INT_MAX)
                    c3 = min(c3, tCost[a][x]+tCost[b][x]);
            }
            
            if (c1==INT_MAX && c2==INT_MAX && c3==INT_MAX/2) return -1;
            
            ans += min(c1, min(c2, c3));
        }
        
        return ans;
    }
};
            
