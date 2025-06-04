class Solution {
  private:
    int lcs(string &s1, string &s2, string &s3){
        if(s1.length() == 0 || s2.length() == 0 || s3.length() == 0) return 0;
        int n = s1.length();
        int m = s2.length();
        int p = s3.length();
        vector<vector<vector<int>>> dp (n + 1, vector<vector<int>> (m + 1, vector<int> (p + 1, 0)));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= p; k++){
                   if(s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]){
                       dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                   } 
                else{
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
        }
        return dp[n][m][p];
    }
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        return lcs(s1, s2, s3);
    }
};
