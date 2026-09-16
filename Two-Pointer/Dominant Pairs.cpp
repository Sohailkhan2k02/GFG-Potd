class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();
		int result = 0;
		int mid = n>> 1;
		sort(arr.begin(), arr.begin() + mid);
		sort(arr.begin() + mid, arr.end());
		int right = mid;
		for (int left = 0; left<mid; ++left) {
			while (right<n && arr[left] >= 5*arr[right])right++;
			result += (right - mid);
		}
		return result;
    }
};
