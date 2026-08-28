class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int prev0 = mat[0][0];
          int prev1 = mat[0][1];
          int prev2 = mat[0][2];

          for (int i = 1; i < mat.size(); i++) {
              int curr0 = mat[i][0] + min(prev1, prev2);

              int curr1 = mat[i][1] + min(prev0, prev2);

              int curr2 = mat[i][2] + min(prev0, prev1);

              prev0 = curr0;
              prev1 = curr1;
              prev2 = curr2;
          }

          return min(prev0, min(prev1, prev2));
    }
};
