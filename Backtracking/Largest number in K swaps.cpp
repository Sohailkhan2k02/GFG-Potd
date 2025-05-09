class Solution {
  public:
    void findMax(string &str, int k, string &maxStr, int idx) {
        if (k == 0) return;
        
        int n = str.size();
        char maxChar = str[idx];
        
        for (int i = idx + 1; i < n; i++) {
            if (str[i] > maxChar) {
                maxChar = str[i];
            }
        }
        
        if (maxChar != str[idx]) k--;
        
        for (int i = n - 1; i >= idx; i--) {
            if (str[i] == maxChar) {
                swap(str[i], str[idx]);
                if (str.compare(maxStr) > 0) {
                    maxStr = str;
                }
                findMax(str, k, maxStr, idx + 1);
                swap(str[i], str[idx]); // backtrack
            }
        }
    }

    string findMaximumNum(string &str, int k) {
        string maxStr = str;
        findMax(str, k, maxStr, 0);
        return maxStr;
    }
};
