//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    void sort012(vector<int>& nums) {
        // code here
        int n=nums.size();
        int i=0,j=0,k=n-1;
        while(j<=k){
            if(nums[j]==0){
                swap(nums[i++],nums[j++]);
            }
            else if(nums[j]==2){
                swap(nums[j],nums[k--]);
            }
            else j++;
        }
    }
};
