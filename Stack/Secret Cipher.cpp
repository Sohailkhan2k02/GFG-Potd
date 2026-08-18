class Solution {
  public:
string compress(string s) {
        int n = s.size();

        // Build LPS array (KMP)
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];

            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }

            if (s[i] == s[j]) {
                j++;
            }

            lps[i] = j;
        }

        string ans = "";

        int i = n - 1;

        while (i >= 0) {

            if (i % 2 == 1) {
                int len = i + 1;

                // Current prefix can be compressed
                if (lps[i] >= len / 2 &&
                    len % (2 * (len - lps[i])) == 0) {

                    ans += '*';

                    // IMPORTANT
                    i = i / 2 + 1;
                }
                else {
                    ans += s[i];
                }
            }
            else {
                ans += s[i];
            }

            i--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
