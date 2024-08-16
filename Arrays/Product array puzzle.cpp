//T.C : O(n)
//S.C : O(n)
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
       
        //code here        
        int n=nums.size();
        long long pre=1,suf=1;
        vector<long long int>ans(n);
        for(int i=0; i<n; i++){
            ans[i]=pre;
            pre=pre*nums[i];
        }
        for(int i=n-1; i>=0; i--){
            ans[i]*=suf;
            suf=suf*nums[i];
        }
        
        return ans;
    }
};
