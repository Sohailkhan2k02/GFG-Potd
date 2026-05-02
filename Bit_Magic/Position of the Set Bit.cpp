class Solution {
  public:
    int findPosition(int n) {
        // code here
        if (n <= 0 || (n & (n - 1)) != 0) return -1;
        return __builtin_ctz(n) + 1;
    }
};
