//T.C : O(logn)
//S.C : O(1)
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        int start = 0, end = n - 1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
    
            if (arr[mid] == key)
                return mid;
    
            if (arr[start] <= arr[mid]) {
                if (arr[start] <= key && key <= arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (arr[mid] <= key && key <= arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
    
        return -1;
    }
};
