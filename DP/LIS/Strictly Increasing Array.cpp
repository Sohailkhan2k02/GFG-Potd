//T.C : O(n*n)
//S.C: O(n)
class Solution {
  public:

    int min_operations(vector<int>& nums) {
        // Code here
        int n=nums.size();
        int mxx=1;
        vector<int>dp(n+1,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(i-j<=nums[i]-nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            mxx=max(mxx,dp[i]);
        }
        return n-mxx;
    }
};
