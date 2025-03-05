//T.C : O(n*n)+O(nlogn)
//S.C : O(n)
class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int ans = 0;

        for (string &word : words) {
            int maxLength = 0;
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                maxLength = max(maxLength, dp[prev]);
            }
            dp[word] = maxLength + 1;
            ans = max(ans, dp[word]);
        }

        return ans;
    }
};
