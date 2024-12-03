//T.C : O(n+m)
//S.C : O(n+m)
class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        string comb = s1 + s1;
        return ( s1.length() == s2.length() ) && ( comb.find( s2 ) != string::npos );
    }
};
