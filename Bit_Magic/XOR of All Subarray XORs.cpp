class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int res = 0;
                int n = arr.size();
                if (n % 2)
                    for (int i = 0; i < n; i += 2)
                        res ^= arr[i];
                return res;
    }
};
