class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int maxXor=INT_MIN;
        int currXor=0;
        int i=0;
        for(int j=0;j<arr.size();j++){
            currXor^=arr[j];
            if(j-i+1==k){
               maxXor=max(maxXor,currXor);
               currXor^=arr[i++];
            }
        }
        return maxXor;
    }
};
