// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
    int n = s.size();
    int i = 0;
    int zero = -1, one = -1, two = -1;
    int maxi = INT_MAX;
    
    while (i < n) {
        if (s[i] == '0') zero = i;
        if (s[i] == '1') one = i;
        if (s[i] == '2') two = i;

        if (zero != -1 && one != -1 && two != -1) {
            maxi = min(maxi, i + 1 - min({zero, one, two}));
        }

        i++;
    }

    if (maxi != INT_MAX) {
        return maxi;
    }
    return -1;
        
    }
};
