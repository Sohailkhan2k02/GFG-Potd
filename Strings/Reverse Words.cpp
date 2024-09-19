//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string s) {
        // code here
        stringstream ss(s);
        string token="";
        string res="";
        while(getline(ss,token,'.')){
            res=token+'.'+res;
        }
        res.pop_back();
        return res;
    }
};
