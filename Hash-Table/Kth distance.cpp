//T.C : O(n)
//S.C : O(n)
class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        int n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0; i<n; i++){
            if(mpp.find(arr[i])!=mpp.end()){
                if(i-mpp[arr[i]]<=k){
                    return true;
                }
            }
            mpp[arr[i]]=i;
        }
        return false;
    }
};
