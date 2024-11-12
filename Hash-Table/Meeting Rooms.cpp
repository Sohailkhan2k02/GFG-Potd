//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        map<int,int>mpp;
        for(auto i:arr){
            int u=i[0],v=i[1];
            mpp[u]++;
            mpp[v]--;
        }
        int cnt=0;
        for(auto i:mpp){
            cnt+=i.second;
            if(cnt>1) return false;
        }
        return true;
    }
};
