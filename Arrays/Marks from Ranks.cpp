class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        int n = l.size();

        vector<int> vec(n + 1, 0);

        for (int i = 0; i < n; i++)
            vec[i + 1] = vec[i] + (r[i] - l[i]) + 1;

        vector<int> res;

        for (auto it : rank) {
            int pos = lower_bound(vec.begin(), vec.end(), it) - vec.begin();
            int offset = it - vec[pos - 1] - 1;
            res.push_back(l[pos - 1] + offset);
        }

        return res;
    }
};
