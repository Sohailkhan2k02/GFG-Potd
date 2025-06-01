class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        unordered_set<int>s;
        int count=0;
        for(int i=0;i<mat1[0].size();i++){
            for(int j=0;j<mat1.size();j++){
                s.insert(mat1[i][j]);
            }
        }
            
            for(int i=0;i<mat2[0].size();i++){
            for(int j=0;j<mat2.size();j++){
                if(s.find(x-mat2[i][j])!=s.end())
                count++;
            }
        }
        return count;
    }
};
