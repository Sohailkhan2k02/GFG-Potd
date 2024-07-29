//T.C : O(3n^2)
//S.C : O(l * x)
class Solution{
    public:
    void f(int i, int j, vector<vector<int>>& mat, int n, int m, string move, vector<vector<int>>& vis, vector<string>& res) {
        if (i == n - 1 && j == m - 1) {
            res.push_back(move);
            return;
        }
    
        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, -1, 1, 0};
        string dir = "DLRU";
        vis[i][j]=1;
        for (int k = 0; k < 4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1) {
                f(nrow, ncol, mat, n, m, move + dir[k], vis, res);
            }
        }
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();
        vector<string>res;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(mat[0][0]==1){
            f(0,0,mat,n,n,"",vis,res);
        }
        return res;
    }
};

    
