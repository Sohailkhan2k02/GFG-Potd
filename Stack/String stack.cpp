class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int i = (int)pat.size() - 1;
        int j = (int)tar.size() - 1;

        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                // this pat[i] can be the final matched char
                i--;
                j--;
            } else {
                // this pat[i] must have been removed (paired push-pop),
                // so skip it and its partner (i-1) in reverse.
                i -= 2;
            }
        }
        return j < 0; 
    }
};
