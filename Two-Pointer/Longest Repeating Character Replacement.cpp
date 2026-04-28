class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
         int ans =0;
         int n = s.size();
          for(char c = 'A' ;c <= 'Z'; c++){
              int i =0 , j = 0,temp = k;
              while( j<n){
                  if( s[j] != c && temp ==0){
                       while( i<=j && s[i]==c) i++;
                        i++;
                        temp++;
                  } 
                  if( s[j] != c && temp >0){
                      temp--;
                  }
                   j++;
                    ans = max ( ans , j-i);
              }
          }
           return ans;
    }
};
