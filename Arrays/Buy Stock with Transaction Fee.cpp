class Solution {
  public:
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        if (n == 0) return 0;

        long long hold = -arr[0]; 
        long long sell = 0;

        for (int i = 1; i < n; i++) {
            long long prev_hold = hold;
        
            hold = max(hold, sell - arr[i]);
        
            sell = max(sell, prev_hold + arr[i] - k);
        }
        return (int)sell;
    }
};
