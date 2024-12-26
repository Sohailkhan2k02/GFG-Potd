//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        map<int,int>mpp;
        for(auto i:arr){
            if(mpp.find(target-i)!=mpp.end()){
                return true;
            }
            mpp[i]++;
        }
        return false;
    }
};
