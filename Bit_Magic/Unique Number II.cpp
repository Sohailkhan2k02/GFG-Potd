//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int xr=0;
        for(auto i:arr)xr^=i;
        int t=xr&-xr;
        int s1=0,s2=0;
        for(auto i:arr){
            if((i&t)>0) s1^=i;
            else s2^=i;
        }
        if(s1>s2){
            return {s2,s1};
        }
        else{
            return {s1,s2};
        }
        return {-1};
    }
};
