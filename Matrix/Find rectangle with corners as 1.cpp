class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        for(int i=0;i<m-1;i++){
            for(int j=i+1;j<m;j++){
                bool flag=0;
                for(int k=0;k<n;k++){
                    if(mat[k][i] && mat[k][j]){
                        if(flag)
                        return 1;
                        flag=1;
                    }
                }
            }
        }
        return 0;
    }
};
