class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        int track = 0;
        for(char c: s){
            track = track^(1<<(c-'a'));
        }
        int set_bits = __builtin_popcount(track);
        if(set_bits>1)return false;
        return true;
    }
};
