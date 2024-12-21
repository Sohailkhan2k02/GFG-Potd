//T.C : O(n*m)
//S.C : O(1)
class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        for(int i=0; i<n; i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<m; j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};
