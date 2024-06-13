//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
  const int mod=1e9+7;
    int padovanSequence(int n) {
        // code here.
        if(n==0 || n==1 || n==2) return 1;
        int a=1,b=1,c=1;
        for(int i=3; i<=n; i++){
            int d=(a+b)%mod;
            a=b;
            b=c;
            c=d;
        }
        return c;
    }
};
