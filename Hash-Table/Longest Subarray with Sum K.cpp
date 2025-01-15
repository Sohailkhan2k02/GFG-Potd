//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        map<int,int>mpp;
        mpp[0]=-1;
        int maxi=0,sum=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(mpp.find(sum-k)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum-k]);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return maxi;
    }
};
