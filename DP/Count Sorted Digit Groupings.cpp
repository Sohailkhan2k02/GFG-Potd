class Solution {
  public:
    int validGroups(string &s) {
        // code here
        int n = s.size(), mxSum = 9*n;
		vector<vector<int>> dp(n + 1, vector<int>(mxSum + 1));
		for (int i = 0; i <= mxSum; i++) {
			dp[n][i] = 1;
		}
		
		for (int i = n - 1; i >= 0; i--) {
			for (int prevSum = 0; prevSum <= mxSum; prevSum++) {
				int currSum = 0;
				for (int j = i; j<n; j++) {
					currSum += (s[j]-'0');
					if (currSum >= prevSum) {
						dp[i][prevSum] += dp[j + 1][currSum];
					}
				}
			}
		}
		
		return dp[0][0];
    }
};
