class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here
        int i = 0;
        int j = 0;
        
        while(i < s1.length() && j < s2.length()) {
            
            if(s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        
        return i == s1.length();
    }
};
