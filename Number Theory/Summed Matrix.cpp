//T.C : O(1)
//S.C : O(1)
class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(q>2*n or q<2)return 0;
        return abs(n-abs(n+1-q));
    }
};
