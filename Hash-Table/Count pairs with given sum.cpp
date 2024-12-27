//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int cnt=0;
        map<int,int>mpp;
        for(auto i:arr){
            if(mpp.find(target-i)!=mpp.end()){
                cnt+=mpp[target-i];
            }
            mpp[i]++;
        }
        return cnt;
    }
};
