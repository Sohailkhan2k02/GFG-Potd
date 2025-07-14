class Solution {
  public:
    bool isValid(string& t){
        int num = 0, n = t.size();
        for(int i = 0; i < n; i++){
            if(t[i] == '0') continue;
            num += (1 << (n-i-1));
        }
        while(num % 5 == 0){
            num /= 5;
        }
        return num == 1;
    }
    int dp[31][31];
    int solve(string& s, int i, int j){
        if(i > j) return 0;
        int ways = 1e9;
        string t = "";
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        for(int k = i; k <= j; k++){
            t += s[k];
            if(t[0] == '0') break;
            if(isValid(t)){
                ways = min(ways, 1 + solve(s, k+1, j));
            }
        }
        return dp[i][j] = ways;
    }
  
    int cuts(string s) {
        // code here
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int ans = solve(s, 0, n-1);
        return ans == 1e9 ? -1 : ans;
    }
};
