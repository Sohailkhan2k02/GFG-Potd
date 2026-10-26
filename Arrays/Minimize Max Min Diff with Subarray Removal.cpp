
class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        vector<int>suffmin(n),suffmax(n);
        int maxi=arr[n-1],mini=arr[n-1];
        for(int i=n-1; i>=0; i--){
            mini=min(mini,arr[i]);
            maxi=max(maxi,arr[i]);
            suffmin[i]=mini;
            suffmax[i]=maxi;
        }
        int ans=INT_MAX,premax=arr[0],premin=arr[0];
        ans = min( ans , suffmax[k] - suffmin[k]);
        
        for(int i=1;i < n-k;i++)
        {
            int minval = min(premin , suffmin[i+k]);
            int maxval = max(premax , suffmax[i+k]);
            ans = min(ans , maxval - minval);
            premax = max(premax , arr[i]);
            premin = min(premin , arr[i]);

        }
        
        // ignoring the last k ements 
        ans = min(ans  , premax - premin);
        return ans;
    }
};
