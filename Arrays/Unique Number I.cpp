//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int xorr = 0;
        for(int val : arr) xorr ^= val;
        return xorr;
        
    }
};
