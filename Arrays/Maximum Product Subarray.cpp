//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &nums) {
        // Your Code Here
        int n=nums.size();
        using ll=long long;
        ll pre=1,suff=1,maxi=INT_MIN;
        for(int i=0; i<n; i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            pre=pre*nums[i];
            suff=suff*nums[n-i-1];
            maxi=max({maxi,pre,suff});
        }
        return maxi;
    }
};
