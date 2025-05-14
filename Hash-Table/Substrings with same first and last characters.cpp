//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int countSubstring(string &s) {
        // code here
       vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int count = 0;
        for (int f : freq) {
            count += (f * (f + 1)) / 2;
        }

        return count;
    }
};
