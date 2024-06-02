//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        vector<int>v;
        int xr=0;
        for(int i=q-1;i>=0;i--){
            if(queries[i][0]==1){
                xr^=queries[i][1];
            }else{
                v.push_back(queries[i][1]^xr);
            }
        }
        v.push_back(xr);
        sort(v.begin(),v.end());
        return v;
    }
};
