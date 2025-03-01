//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    string decodedString(string &s) {
        // code here
        if(s.length() == 0) return s;
        stack<int> Int;
        stack<string> Str;
        string temp = "";
        int n = 0;
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
               n = n*10+(s[i]-'0');
            }else if(s[i] == '['){
                Int.push(n);
                n = 0;
                Str.push(temp); //Mistake in This Place was Done by me
                temp = "";
            }else if(s[i] == ']'){
                int k = Int.top();
                Int.pop();
                for(int j=1;j<=k;j++){
                     Str.top() += temp;
                }
                temp = Str.top();
                Str.pop();
                
               
            }else{
                temp += s[i];

            }

        }
        return temp;
    }
};
