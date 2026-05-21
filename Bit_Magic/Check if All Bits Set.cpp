class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        if(n==0){
            return false;
        }
        return (n&(n+1))==0;
    }
};
