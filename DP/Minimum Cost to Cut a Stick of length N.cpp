class Solution {
  public:
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        vector<vector<int>>dp(cuts.size()+2, vector<int>(cuts.size()+2, 0));
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        for(int l = cuts.size()-2;l>=1;l--){
            for(int r = 1;r<=cuts.size()-2;r++){
                if(l > r){
                    dp[l][r] = 0;
                    continue;
                }
                int ans = INT_MAX;
                for(int i = l;i<=r;i++){
                    int temp = cuts[r+1] - cuts[l-1];
                    int temp1 = l > i-1 ? 0 : dp[l][i-1];
                    int temp2 = i+1 > r ? 0 : dp[i+1][r];
                    ans = fmin(ans, temp + temp1 + temp2);
                }
                dp[l][r] = ans;
            }
        }
        return dp[1][cuts.size()-2];
    }
};
