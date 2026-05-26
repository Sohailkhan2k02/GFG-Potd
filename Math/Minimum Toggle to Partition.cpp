class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
        int zero=0;
      for(int x: arr) if(!x) zero++;
      
      int one=0;
      int ans=zero;
      
      for(int x: arr){
        if(x==1) one++;
        else zero--;
        
        ans=min(ans, zero+one);
      }
      
      return ans;
        
    }
};
