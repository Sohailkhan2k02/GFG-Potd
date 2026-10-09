class Solution {
  public:
    int minOperation(int n) {
        // code here
        int cnt =0;
       while(n>0){
           if(n%2){
               n-=1;
           }
           else{
               n = n/2;
           }
           cnt+=1;
       }
       return cnt;
    }
};
