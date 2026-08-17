class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        // code here
        int total = n * n;

        vector<int> jump(total + 1, 0);

        for (int i = 0; i < (int)lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < (int)sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        vector<bool> visited(total + 1, false);
        queue<pair<int, int>> q;

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [cell, throws] = q.front();
            q.pop();

            if (cell == total) {
                return throws;
            }

            // Try every possible dice result from 1 to 6.
            for (int dice = 1; dice <= 6; ++dice) {
                int next = cell + dice;

                if (next > total) {
                    continue;
                }

                if (jump[next] != 0) {
                    next = jump[next];
                }

                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, throws + 1});
                }
            }
        }

        return -1;
        
    }
};
