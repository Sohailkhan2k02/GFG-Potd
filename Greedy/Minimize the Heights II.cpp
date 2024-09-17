//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n==1) return 0;
        sort(begin(arr),end(arr));
        int diff=arr[n-1]-arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]-k<0) continue;
            int maxi=max(arr[i-1]+k,arr[n-1]-k);
            int mini=min(arr[0]+k,arr[i]-k);
            diff=min(diff,maxi-mini);
        }
        return diff;
    }
};
