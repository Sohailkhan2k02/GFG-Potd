//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int diff=arr[n-1]-arr[0];
        for(int i=1; i<n; i++){
            int mn=min(arr[0]+k,arr[i]-k);
            int mx=max(arr[i-1]+k,arr[n-1]-k);
            diff=min(diff,mx-mn);
        }
        
        return diff;
    }
};
