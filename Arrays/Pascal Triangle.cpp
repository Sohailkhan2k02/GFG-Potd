//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    const int mod=1e9+7;
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>>ans;
        vector<int>result;
        for(int i=0; i<n; i++){
            vector<int>temp(i+1);
            temp[0] =1;
            temp[i] =1;
            for(int j=1; j<i; j++){
                temp[j] = (ans[i-1][j-1]+ans[i-1][j])%mod;
            }
            ans.push_back(temp);
        }
        for(auto it: ans[n-1]){
            result.push_back(it);
        }
        return result;
    }
};
