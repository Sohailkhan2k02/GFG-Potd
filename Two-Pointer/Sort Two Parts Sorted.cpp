class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        // code here
        int n = arr.size();
		int first = 0, second = -1;
		vector<int>temp = arr;
		for (int i = 1; i<n; ++i) {
			if (arr[i]<arr[i - 1]) {
				second = i;
				break;
			}
		}
		if (second != -1) {
			int i = first, j = second;
			int idx = 0;
			while (i<second && j<n) {
				if (temp[i] <= temp[j]) {
					arr[idx] = temp[i++];
				}
				else
					arr[idx] = temp[j++];
				idx++;
			}
			while (i<second) {
				arr[idx++] = temp[i++];
			}
			while (j<n) {
				arr[idx++] = temp[j++];
			}
		}
    }
};
