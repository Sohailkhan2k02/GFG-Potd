class Solution {
  public:
    int minProd(vector<int>& arr) {
        // code here
        int ans = INT_MAX;
        
        int n = arr.size();
        
        for (int mask = 1; mask < (1 << n); mask++) {
            int prod = 1;
            
            for (int i = 0; i < n; i++) {
                
                if (mask & (1 << i)) {
                    prod *= arr[i];
                }
            }
            
            ans = min(ans, prod);
        }
        
        return ans;
    }
};
