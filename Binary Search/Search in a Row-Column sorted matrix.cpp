//T.C : O(n*logm)
//S.C : O(1)
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int n=mat.size(),m=mat[0].size();
        for(int i=0; i<n; i++){
            int l=0,h=m-1;
            while(l<=h){
                int m=l+(h-l)/2;
                if(mat[i][m]==x){
                    return true;
                }
                else if(mat[i][m]<x){
                    l=m+1;
                }
                else h=m-1;
            }
        }
        return false;
    }
};
