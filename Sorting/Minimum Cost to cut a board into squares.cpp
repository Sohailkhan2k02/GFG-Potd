class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.rbegin(), x.rend());
        sort(y.rbegin(), y.rend());
        
        int i = 0, j = 0;
        long long cost = 0;
        long long horizontal_segments = 1, vertical_segments = 1;
        
        // Greedily pick the largest cost first
        while (i < (int)x.size() && j < (int)y.size()) {
            if (x[i] > y[j]) {
                cost += 1LL * x[i] * horizontal_segments;
                vertical_segments++;
                i++;
            } else {
                cost += 1LL * y[j] * vertical_segments;
                horizontal_segments++;
                j++;
            }
        }
        
        // Process remaining vertical cuts
        while (i < (int)x.size()) {
            cost += 1LL * x[i] * horizontal_segments;
            i++;
        }
        
        // Process remaining horizontal cuts
        while (j < (int)y.size()) {
            cost += 1LL * y[j] * vertical_segments;
            j++;
        }
        
        return (int)cost;
    }
};
