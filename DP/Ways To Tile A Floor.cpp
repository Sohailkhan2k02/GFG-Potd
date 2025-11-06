class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        int a=0,b=1,c=0;
        for(int i=2;i<=n+1;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
