class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int N=arr.size();
         unordered_map<int, int>mpp;
        mpp[0] = 1;
        int presum =0, cnt =0;
        
        for(int i=0; i<N; i++){
            presum+=arr[i];
            int removal = presum-k;
            cnt+=mpp[removal];
            mpp[presum]+=1;
        }
        return cnt;
    }
};
