class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        return n&(n-1);
    }
};
