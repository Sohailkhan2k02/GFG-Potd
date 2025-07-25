class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalSum = 0;
        int currMaxSum = 0, currMinSum = 0;
        int maxSum = arr[0], minSum = arr[0];

        for (int i = 0; i < arr.size(); i++) {
            currMaxSum = max(currMaxSum + arr[i], arr[i]);
            maxSum = max(maxSum, currMaxSum);
            currMinSum = min(currMinSum + arr[i], arr[i]);
            minSum = min(minSum, currMinSum);
            totalSum = totalSum + arr[i];
        }

        int normalSum = maxSum;
        int circularSum = totalSum - minSum;
        if (minSum == totalSum)
            return normalSum;

        return max(normalSum, circularSum);
    }
};
