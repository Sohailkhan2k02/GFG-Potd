//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
  public:
    
    bool valid(vector<vector<int>>& mat, int val, int x, int y) {
        for(int j = 0; j < mat[0].size(); j++) if(mat[x][j] == val) return false;
        for(int i = 0; i < mat.size(); i++) if(mat[i][y] == val) return false;
        
        x = 3*(x/3), y = 3*(y/3);
        
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(mat[x + i][y + j] == val) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<int>>& mat, vector<pair<int, int>>& to_fill, int index) {
        if(index >= to_fill.size()) return true;
        
        bool res = false;
        
        for(int i = 1; i <= 9; i++) {
            int x = to_fill[index].first, y = to_fill[index].second;
            
            if(valid(mat, i, x, y)) {
                mat[x][y] = i;
                res |= solve(mat, to_fill, index + 1);
                if(res) return true;
                mat[x][y] = 0;
            }
        }
        
        return res;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        vector<pair<int, int>> to_fill;
        int n = mat.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) to_fill.push_back({i, j});
            }
        }
        
        solve(mat, to_fill, 0);
    }
};
