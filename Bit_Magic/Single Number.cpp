//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        int xr=0;
        for(auto i:arr){
            xr^=i;
        }
        return xr;
    }
};
