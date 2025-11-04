class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        vector<int> dp(height.size(), 0);
        
        for(int i = height.size()-2;i>=0;i--){
            int a = abs(height[i]-height[i+1]) + dp[i+1];
            int b = INT_MAX;
            if (i + 2 < height.size())
                b = abs(height[i] - height[i + 2]) + dp[i + 2];
            
            dp[i] = min(a,b);
        }
        
        return dp[0];
    }
};
