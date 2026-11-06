class Solution {
  public:
    int countBT(int h) {
        // code here
        long int mod=1000000007;
               long long int a=1;
               long long int b=1;
               long long int c;
               for(int i=2;i<=h;i++){
                   c =b*((2*a)+b)%mod;
                   a=b;
                   b=c;
               }
               return c;
    }
};
