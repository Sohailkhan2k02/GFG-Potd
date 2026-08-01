class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int> diff(n+1, 0);
        int m = a.size();
        
        for (int i=0; i<m; i++) {
            
            int l = a[i];
            int r = b[i];
            int val = k[i];
            
            diff[l] += val;
            diff[r+1] -= val;
        }
        
        int ans = diff[0];
        for (int i=1; i<n; i++) {
            diff[i] += diff[i-1];
            
            ans = max(ans, diff[i]);
        }
        
        return ans;
    }
};
