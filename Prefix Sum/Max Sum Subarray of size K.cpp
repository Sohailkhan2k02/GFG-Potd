class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;

        // Sum of first k elements
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        int maxSum = sum;

        // Sliding window
        for (int i = k; i < n; i++) {
            sum = sum + arr[i] - arr[i - k];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
