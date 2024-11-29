//T.C : O(n+m)
//S.C : O(n+m)
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        map<char,int>m1,m2;
        for(auto i:s1){
            m1[i]++;
        }
        for(auto i:s2){
            m2[i]++;
        }
        return m1==m2;
    }
};
