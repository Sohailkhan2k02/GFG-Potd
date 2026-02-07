class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        int currSum = 0;
        for(int i=0;i<n;i++){
            currSum+=(arr[i]*i);
        }
        ans = max(ans, currSum);
        int total = 0;
        for(int i=0;i<n;i++) total+=arr[i];
        for(int i=0;i<n-1;i++){
            currSum+=((arr[i]*n)-total);
            ans = max(ans, currSum);
        }
        return ans;
    }
};
