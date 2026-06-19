class Solution {
  public:
    vector<int> optimalArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, 0);
        
        // Base case: 1 element requires 0 operations
        ans[0] = 0; 
        
        for (int i = 1; i < n; i++) {
            // Bitwise for speed improve (i/2)
            ans[i] = ans[i - 1] + (arr[i] - arr[i >> 1]); 
        }
        
        return ans;
    }
};
