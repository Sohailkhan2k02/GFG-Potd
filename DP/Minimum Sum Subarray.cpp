class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        int sum = 0 , mini = 1e9 , n = arr.size() ;
                for(int i=0;i<n;i++){
                    sum+=arr[i];
                    mini = min(mini,sum);
                    if(sum>0)sum = 0 ;
                }
                return mini ; 
    }
};
