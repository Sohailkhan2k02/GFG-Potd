class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());

                int low = 1, high = arr.back() + k;

                while (low < high) {
                    int mid = low + (high - low) / 2;

                    int missing = mid - 
                        (upper_bound(arr.begin(), arr.end(), mid) - arr.begin());

                    if (missing < k)
                        low = mid + 1;
                    else
                        high = mid;
                }

                return low;
    }
};
