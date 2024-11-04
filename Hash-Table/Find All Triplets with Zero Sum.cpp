//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> result;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int target = -1 * (arr[i] + arr[j]);
                if (mp.find(target) != mp.end()) {
                    for (int idx : mp[target]) {
                        if (i < idx && j < idx) {
                            result.push_back({i, j, idx});
                        }
                    }
                }
            }
        }
        return result;
    }
};
