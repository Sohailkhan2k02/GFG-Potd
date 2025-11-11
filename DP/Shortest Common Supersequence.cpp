//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int n, int m)
    {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
       }
       for (int i = 0; i <= m; i++) {
       dp[0][i] = 0;
       }

      for (int ind1 = 1; ind1 <= n; ind1++) {
       for (int ind2 = 1; ind2 <= m; ind2++) {
         if (s1[ind1 - 1] == s2[ind2 - 1])
          dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
         else
          dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
       }
      }
      return n+m-dp[n][m];
    }
};
