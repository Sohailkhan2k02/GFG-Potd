//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        int n=arr.size();
        long long maxi=arr[0];
        long long sum=arr[0];
        for(int i=1; i<n; i++){
            if(sum<=0) sum=0;
            sum+=arr[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
