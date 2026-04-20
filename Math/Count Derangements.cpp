class Solution {
  public:
    int fact(int num){
       if(num<=1)return 1;
       return num*fact(num-1);
   }
  
    int derangeCount(int n) {
        // code here
        int ans=0;
        for(int i=0;i<=n;i++){
            ans+=fact(n)*(pow(-1,i)/fact(i));
        }
        return ans;
    }
};
