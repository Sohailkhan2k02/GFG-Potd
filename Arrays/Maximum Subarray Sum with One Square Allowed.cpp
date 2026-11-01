class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
                int fAns = INT_MIN;
                int activeSum = 0;
                int dormantSum = 0;
                for(int i=0;i<n;i++){
                    activeSum = max(activeSum + arr[i], dormantSum + arr[i] * arr[i]);
                    dormantSum = max(dormantSum + arr[i], 0);
                    fAns = max(fAns, max(activeSum, dormantSum));
                }
                return fAns;
    }
};
