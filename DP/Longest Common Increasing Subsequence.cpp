class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n=a.size(), m=b.size();
      vector<int> dp(m+1, 0);
      
      for(int &x: a){
        int c=0;
        for(int i=0;i<m;i++){
          if(b[i]==x)
            dp[i] = (dp[i], c+1);
          if(b[i] < x)
            c = max(dp[i], c);
        }
      }
      
      
      int ans = 0;
      for(int &x: dp)
        ans = max(ans, x);
      
      return ans;
    }
};
