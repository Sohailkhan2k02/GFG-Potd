class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int maxi = INT_MIN, n = mat.size();
        for (int i = 0; i < n; i++){
            maxi = max(maxi, accumulate(mat[i].begin(), mat[i].end(), 0));
        }
        int tot = 0;
        for (int j = 0; j < n; j++){
            int sum = 0;
            for (int i = 0; i < n; i++){
                sum += mat[i][j];
                tot += mat[i][j];
            }
            maxi = max(maxi, sum);
        }
        return n*maxi-tot;
    }
};
