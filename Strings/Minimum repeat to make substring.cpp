//T.C: O(n+n^2/m)
//S.C : O(n)
class Solution {
  public:
    int minRepeats(string& A, string& B) {
        // code here
        string c = "";
        int count = 0;
        while (c.length() <= 2 * B.length()) {
            c += A;
            count++;
            if (c.find(B) != string::npos) {
                return count;
            }
        }
        return -1;
        
    }
};
