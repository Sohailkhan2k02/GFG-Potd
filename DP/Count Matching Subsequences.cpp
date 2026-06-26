class Solution {
  public:
  int mod = 1e9+7;
    int countWays(string &s1, string &s2) {
        // code here
        int n = s1.length(), m = s2.length();
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        curr[0] = 1;
        prev[0] = 1;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                curr[j] = prev[j]%mod;
                if(s1[i-1] == s2[j-1])
                    curr[j] = (curr[j]+prev[j-1])%mod;
            }
            prev = curr;
        }
        return prev[m];
    }
};
