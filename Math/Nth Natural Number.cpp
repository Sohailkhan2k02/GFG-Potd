//T.C : O(logn)
//S.C : O(1)
class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        using ll=long long;
        ll res = 0;
        ll mul = 1;
        while(n > 0) {
            res += (n % 9) * mul;
            n /= 9;
            mul *= 10;
        }
        return res;
    }
};
