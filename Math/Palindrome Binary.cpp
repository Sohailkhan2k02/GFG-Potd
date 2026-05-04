class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        vector<int> bits;
    bits.reserve(32);
    
    // Getting binary representation
    while(n > 0) {
        (n&1) ? bits.push_back(1) : bits.push_back(0);
        n >>= 1;
    }
    
    int l = 0;
    int r = bits.size() - 1;
    
    // Checking palindrome
    while(l <= r) {
        if(bits[l] != bits[r]) {
            return false;
        }
        
        l++;
        r--;
    }
    
    return true;
    }
};
