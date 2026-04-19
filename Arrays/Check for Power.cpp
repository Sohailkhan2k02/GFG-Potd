class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        for(int i = 0; i<1000;i++){
           if(pow(x,i) == y){
               return true;
           }
        }
    }
};
