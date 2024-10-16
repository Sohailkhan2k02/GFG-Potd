//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    bool checkSorted(vector<int>& arr) {
        int count = 0, n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] != i + 1) count++;
        }
        // 0 is valid
        // 1 is impossible
        // 2 is false
        // 3 is valid
        // 4 is skeptical
        return count == 0 || count == 3 || (count == 4 && verify(arr));
    }

    bool verify(vector<int>& arr) {
        int a = -1, b = -1, c = -1, d = -1, n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] != i + 1) {
                if(a == -1)       a = i;
                else if(b == -1)  b = i;
                else if(c == -1)  c = i;
                else              d = i;
            }
        }
        return verifySwap(arr, a, b) || verifySwap(arr, a, c) || verifySwap(arr, a, d);
    }

    bool verifySwap(vector<int>& list, int i, int j) {
        return list[i] == j + 1 && list[j] == i + 1;
    }
};
