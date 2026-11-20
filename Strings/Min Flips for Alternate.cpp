class Solution {
  public:
    int minFlips(string &s) {
        // code here
        int cnt1 = 0, cnt2 = 0;

                for(int i = 0; i < s.size(); i++) {
                    if(s[i] != (i % 2 == 0 ? '0' : '1')) cnt1++;
                    if(s[i] != (i % 2 == 0 ? '1' : '0')) cnt2++;
                }

                return min(cnt1, cnt2);
    }
};
