class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int ans = 0;
        int maxSum = 0;
        int count = 0;
        int sum = 0;
        
        for (int x : arr) {
            
            int v = (x == 0) ? 1 : -1;
            
            sum = max(v, sum+v);
            maxSum = max(maxSum, sum);
            
            if (x == 1) count++;
            
        }
        
        return count + maxSum;
    }
};
