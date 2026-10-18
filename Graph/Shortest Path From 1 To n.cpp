//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        int cnt=0;
        while(n>1){
         if(n%3==0){
             n=n/3;
         }
         else
         n--;
         cnt++;
        }
        
        return cnt;
    }
};
