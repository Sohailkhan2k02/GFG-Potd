class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        int XOR = 0;
        int n = queries.size();
        vector<int>ans;
        
        for(int i=n-1;i>=0;i--){
            int value = queries[i][1];
            if(queries[i][0]==0) ans.push_back(value^XOR);
            else XOR^=value;
        }
        
        ans.push_back(XOR);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};
