//T.C : O(n*m)
//S.C : O(1)
class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int c=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    if(j>0&&matrix[i][j-1]==1){
                        c++;
                    }
                    if(j<m-1&& matrix[i][j+1]==1){
                        c++;
                    }
                    if(i>0&&matrix[i-1][j]==1){c++;}
                    if(i<n-1&&matrix[i+1][j]==1){c++;}
                }
            }
        }
        return c;
    }
};
