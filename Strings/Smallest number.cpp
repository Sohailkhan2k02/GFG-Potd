//T.C : O(D)
//S.C : O(D)
class Solution {
  public:
    string smallestNumber(int S, int D){
        // code here
        string ans = "";
      
      if((9*D) < S ) return "-1";
      
      for(int i = D-1; i >= 0; i--){
          if(9 < S){
              ans = '9' + ans;
              S -= 9;
          }
          else{
              if(i == 0){
                ans = to_string(S) + ans;
                i--;
              }
              else{
                ans = to_string(S-1) + ans;
                 i--;                     
                while(i > 0){
                    ans = '0' + ans;      
                    i--;
                }
                ans = '1' + ans;
                break;
              }
          }
      }
      return ans;
    }
};
