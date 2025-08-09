class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        int n = s.length(), ans = -1;
        vector<int> z(n, 0);
        for(int i = 1, l = -1; i < n; i++) {
            if(l != -1 && i < l + z[l]) z[i] = min(z[i - l], l + z[l] - i);
            while(s[z[i]] == s[i + z[i]]) z[i]++;
            if(i + z[i] > l + z[l]) l = i;
            if(i + z[i] == n) ans = i;
        }
        return ans;
    }
};
