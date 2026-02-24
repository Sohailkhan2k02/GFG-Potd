class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n = a1.size(), ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0, s = 0; i < n; i++) {
            s += (a1[i] - a2[i]);
            if(mp.count(s) != 0) ans = max(ans, i - mp[s]);
            if(mp.count(s) == 0) mp[s] = i;
        }
        return ans;
    }
};
