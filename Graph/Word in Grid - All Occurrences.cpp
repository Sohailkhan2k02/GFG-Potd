class Solution {
  public:
    int n, m;
    vector<vector<vector<int>>> dp;
    
    bool find(vector<vector<char>>& mat, int i, int j, string& word, int idx, int dir) {

        if (idx == word.size())
            return true;

        if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] != word[idx])
            return false;

        if (dp[i][j][dir])

            if (dir == 0)
                return find(mat, i - 1, j - 1, word, idx + 1, 1) ||
                       find(mat, i - 1, j, word, idx + 1, 2) ||
                       find(mat, i - 1, j + 1, word, idx + 1, 3) ||
                       find(mat, i, j - 1, word, idx + 1, 4) ||
                       find(mat, i, j + 1, word, idx + 1, 5) ||
                       find(mat, i + 1, j - 1, word, idx + 1, 6) ||
                       find(mat, i + 1, j, word, idx + 1, 7) ||
                       find(mat, i + 1, j + 1, word, idx + 1, 8);
            else if (dir == 1)
                return find(mat, i - 1, j - 1, word, idx + 1, 1);
            else if (dir == 2)
                return find(mat, i - 1, j, word, idx + 1, 2);
            else if (dir == 3)
                return find(mat, i - 1, j + 1, word, idx + 1, 3);
            else if (dir == 4)
                return find(mat, i, j - 1, word, idx + 1, 4);
            else if (dir == 5)
                return find(mat, i, j + 1, word, idx + 1, 5);
            else if (dir == 6)
                return find(mat, i + 1, j - 1, word, idx + 1, 6);
            else if (dir == 7)
                return find(mat, i + 1, j, word, idx + 1, 7);
            else if (dir == 8)
                return find(mat, i + 1, j + 1, word, idx + 1, 8);
    }

    vector<vector<int>> searchWord(vector<vector<char>>& mat, string& word) {

        n = mat.size();
        m = mat[0].size();

        dp = vector<vector<vector<int>>>(
            n, vector<vector<int>>(m, vector<int>(9, -1)));

        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (find(mat, i, j, word, 0, 0))
                    res.push_back({i, j});

        return res;
        
    
    }
};
