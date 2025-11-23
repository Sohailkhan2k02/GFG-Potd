class Solution {
    int f(int n, vector<int> &p) {
        if(p[n] == -1) return n;
        return p[n] = f(p[n], p);
    }
  public:
    int maxRemove(vector<vector<int>> &stones) {
        // Code here
        int n = stones.size(), r = 0, c = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            r = max(r, stones[i][0]);
            c = max(c, stones[i][1]);
        }
        vector<int> p(r + c + 2, -1), s(r + c + 2, 0);
        for(int i = 0; i < n; i++) {
            int u = f(stones[i][0], p);
            int v = f(stones[i][1] + r + 1, p);
            if(s[u] < s[v]) swap(u, v);
            s[u]++;
            if(u != v) {
                p[v] = u;
                s[u] += s[v];
            }
        }
        for(int i = 0; i < r + c + 2; i++) {
            if(p[i] == -1 && s[i] - 1 > 0) ans += (s[i] - 1);
        }
        
        return ans;
    }
};
