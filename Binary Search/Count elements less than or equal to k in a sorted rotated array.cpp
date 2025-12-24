class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        
        int l = 0, r = n - 1, pivot = 0;
        while (l <= r) {
            if (arr[l] <= arr[r]) { 
                pivot = l; 
                break; 
            }
            int m = l + (r - l) / 2;
            int next = (m + 1) % n;
            int prev = (m + n - 1) % n;
            if (arr[m] <= arr[next] && arr[m] <= arr[prev]) {
                pivot = m;
                break;
            } else if (arr[m] >= arr[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        l = 0; r = n - 1;
        int ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int realMid = (m + pivot) % n;
            if (arr[realMid] <= x) {
                ans = m + 1;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};
