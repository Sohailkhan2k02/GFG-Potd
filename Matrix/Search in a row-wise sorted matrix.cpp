//T.C : O(n*logm)
//S.C : O(1)
class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size(),m=mat[0].size();
        for(int i=0; i<n; i++){
            int l=0,h=m-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(mat[i][mid]==x){
                    return true;
                }
                else if(mat[i][mid]>x){
                    h=mid-1;
                }
                else l=mid+1;
            }
        }
        return false;
    }
};
