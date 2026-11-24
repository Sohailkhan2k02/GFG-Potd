class Solution {
  public:
    vector<int> findPairs(vector<int>& arr) {
        // code here
        map<int, pair<int,int>> mp;
                vector<int> ans = {-1, -1, -1, -1};
                int n = arr.size();

                for (int i = 0; i < n; i++) {
                    for (int j = i + 1; j < n; j++) {
                        int sum = arr[i] + arr[j];

                        if (mp.count(sum)) {
                            auto [a, b] = mp[sum];

                            if (a != i && a != j && b != i && b != j) {
                                vector<int> temp = {a, b, i, j};

                                if (ans[0] == -1 || temp < ans)
                                    ans = temp;
                            }
                        }
                        else {
                            mp[sum] = {i, j};
                        }
                    }
                }

                return ans;
    }
};
