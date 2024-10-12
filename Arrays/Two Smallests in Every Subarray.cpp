//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int pairWithMaxSum(vector<int>& nums) {
        // code here
        int n=nums.size();
        if(n<2) return -1;
        int sum=nums[0]+nums[1];
        for(int i=1; i<n-1; i++){
            sum=max(sum,nums[i]+nums[i+1]);
        }
        return sum;
    }
};
