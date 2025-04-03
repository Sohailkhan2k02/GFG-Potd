//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<pair<int,int>>q;
        int freshO = 0;
        int n = mat.size(), m = mat[0].size();
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0, -1}};
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 1) freshO+=1;
                if (mat[i][j] == 2) q.push({i,j});
            }
        }
        int ans = 0;
        if (freshO == 0) return 0;
        while (!q.empty()){
            int size = q.size();
            if (freshO == 0) return ans;
            ans+=1;
            for (int i=0; i<size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int k=0; k<4; k++){
                    int n_r = dir[k][0] + r;
                    int n_c = dir[k][1] + c;
                    if (n_r < n && n_r >= 0 && n_c < m && n_c >= 0 && mat[n_r][n_c] == 1){
                        mat[n_r][n_c] = 2;
                        q.push({n_r, n_c});
                        freshO-=1;
                    }
                }
            }
        }
        return -1;
    }
};
