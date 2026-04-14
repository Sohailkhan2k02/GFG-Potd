class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string str = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i]==' '){continue;}
            else{str.push_back(s[i]);}
        }
        return str;
    }
};
