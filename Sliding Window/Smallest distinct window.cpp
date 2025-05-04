//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
   int findSubString(string& str) {
    set<char> st;
    for (auto v : str) st.insert(v);
    int head = -1, tail = 0, cnt = 0, n = str.size(), ans = INT_MAX;
    unordered_map<char, int> mp;
    while (tail < n) {
        while (head + 1 < n && cnt < st.size()) {
            head++;
            mp[str[head]]++;
            if (mp[str[head]] == 1) cnt++;
        }
        if (cnt == st.size()) ans = min(ans, head - tail + 1);
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            mp[str[tail]]--;
            if (mp[str[tail]] == 0) cnt--;
            tail++;
        }
    }
    return ans;
}

};
