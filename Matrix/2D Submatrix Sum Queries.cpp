class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries) {
        // code here
        for(auto &i: mat){
            int sum=i[0];
            for(int x=1;x<i.size();x++){
                sum+=i[x];
                i[x]=sum;
            }
        }
        for(int i=0;i<mat[0].size();i++){
            int sum=0;
            for(int j=0;j<mat.size();j++){
                sum+=mat[j][i];
                mat[j][i]=sum;
            }
        }

        vector<int> matSum;
        for(auto q:queries){
            int i=q[0],j=q[1],x=q[2],y=q[3];
            int sum=mat[x][y];
            if(j>0){
                sum-=mat[x][j-1];
            }
            if(i>0){
                sum-=mat[i-1][y];
            }
            if(i>0 && j>0){
                sum+=mat[i-1][j-1];
            }
            matSum.push_back(sum);
        }
        return matSum;
    }
};
