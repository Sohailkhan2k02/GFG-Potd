//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        int n=arr.size();
        unordered_map<int,int>mpp;
        int cnt=0,sum=0;
        mpp[0]=1;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(mpp.find(sum-tar)!=mpp.end()){
                cnt+=mpp[sum-tar];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};
