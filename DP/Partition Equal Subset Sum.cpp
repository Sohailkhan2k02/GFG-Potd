//T.C : O(n)
//S.C : O(10001
class Solution {
  public:
    bool equalPartition(vector<int>& nums) {
        // code here
        bitset<10001>dp;       // 0 is always achievable => dp[0] = 1
        int t=accumulate(nums.begin(),nums.end(),0);
        if(t&1) return false;
        int a=t/2;
        dp[0]=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=a){
                dp|=dp<<nums[i];
            }
        }
        return dp[a];
    }
};
