//T.C : O(1)
//S.C : O(1)
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int temp=n;
        int sum=0;
        int a=temp%10; temp/=10;
        int b=temp%10; temp/=10;
        int c=temp%10; temp/=10;
        sum=(a*a*a)+(b*b*b)+(c*c*c);
        if(sum==n) return "true";
        return "false";
    }
};
