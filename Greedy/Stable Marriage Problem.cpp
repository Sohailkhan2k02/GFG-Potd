class Solution {
  public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
        // code here
        int n = men.size();

        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; w++) {
            for (int i = 0; i < n; i++) {
                rank[w][women[w][i]] = i;
            }
        }

        vector<int> man(n, -1), woman(n, -1), next(n, 0);
        vector<int> free;

        for (int i = 0; i < n; i++) free.push_back(i);

        while (!free.empty()) {
            int m = free.back();
            free.pop_back();

            int w = men[m][next[m]++];
            int curr = woman[w];

            if (curr == -1 || rank[w][m] < rank[w][curr]) {
                woman[w] = m;
                man[m] = w;

                if (curr != -1) free.push_back(curr);
            } else {
                free.push_back(m);
            }
        }

        return man;
    }
};
