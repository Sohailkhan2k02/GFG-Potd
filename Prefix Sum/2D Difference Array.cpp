class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        vector<vector<int>> tmp(mat.size(), vector<int>(mat[0].size(),0));
        for(auto& op:opr){
            int v=op[0], r1=op[1], c1=op[2], r2=op[3], c2=op[4];
            tmp[r2][c2]+=v;
            if(r1>0 && c1>0) tmp[r1-1][c1-1]+=v;
            if(r1>0 ) tmp[r1-1][c2]-=v;
            if(c1>0)tmp[r2][c1-1]-=v;
        }
        for(int i=0;i<mat.size();i++){
            for(int j=mat[0].size()-2;j>=0;j--){
                tmp[i][j]+=tmp[i][j+1];
            }
        }
        for(int i=mat.size()-2;i>=0;i--){
            for(int j=0;j<mat[0].size();j++){
                tmp[i][j]+=tmp[i+1][j];
            }
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                tmp[i][j]+=mat[i][j];
            }
        }
        return tmp;
    }
};
