#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<int> manacher_odd(const string &s) {
        int n = s.size();
        vector<int> d1(n, 0);
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
            d1[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        return d1;
    }

    vector<int> compute_endLen(const string &s, const vector<int> &d1) {
        int n = s.size();
        vector<int> endLen(n, 0);
        vector<int> R(n);
        for (int i = 0; i < n; ++i) R[i] = i + d1[i] - 1;

        deque<int> q;
        for (int p = 0; p < n; ++p) {
            q.push_back(p);

            while (!q.empty() && R[q.front()] < p) q.pop_front();

            if (!q.empty()) {
                endLen[p] = 2 * (p - q.front()) + 1;
            } else {
                endLen[p] = 0;
            }
        }
        return endLen;
    }

  public:
    int maxSum(string &s) {
        int n = s.size();
        if (n < 2) return 0;

        vector<int> d1 = manacher_odd(s);
        vector<int> endLen = compute_endLen(s, d1);

        string rs = s;
        reverse(rs.begin(), rs.end());
        vector<int> d1r = manacher_odd(rs);
        vector<int> endLenR = compute_endLen(rs, d1r);

        vector<int> startLen(n, 0);
        for (int i = 0; i < n; ++i) {
            startLen[n - 1 - i] = endLenR[i];
        }

        vector<int> bestPref(n, 0), bestSuf(n, 0);
        bestPref[0] = endLen[0];
        for (int i = 1; i < n; ++i) bestPref[i] = max(bestPref[i - 1], endLen[i]);

        bestSuf[n - 1] = startLen[n - 1];
        for (int i = n - 2; i >= 0; --i) bestSuf[i] = max(bestSuf[i + 1], startLen[i]);

        int ans = 0;
        for (int i = 0; i + 1 < n; ++i) {
            ans = max(ans, bestPref[i] + bestSuf[i + 1]);
        }
        return ans;
    }
};
