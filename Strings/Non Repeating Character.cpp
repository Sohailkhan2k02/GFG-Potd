//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        int n=s.size();
        map<char,int>mpp;
        for(auto i:s){
            mpp[i]++;
        }
        for(int i=0; i<n; i++){
            if(mpp[s[i]]==1){
                return s[i];
            }
        }
        return '$';
    }
};
