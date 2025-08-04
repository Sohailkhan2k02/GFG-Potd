class Solution {
  public:
    int kadane(vector<int>& arr) {
        int curr = arr[0], maxSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);
            maxSum = max(maxSum, curr);
        }
        return maxSum;
    }

    int maxRectSum(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int maxSum = INT_MIN;

        for (int left = 0; left < m; left++) {
            vector<int> temp(n, 0);

            for (int right = left; right < m; right++) {
                for (int i = 0; i < n; i++) {
                    temp[i] += mat[i][right];
                }

                // Call Kadane on the compressed 1D array
                maxSum = max(maxSum, kadane(temp));
            }
        }

        return maxSum;
    }
};
