class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int l=0,r=0;
        for(char &c:s)
        {
            if(c=='(') ++l;
            else
            {
                if(l>0) --l;
                else ++r;
            }
        }
        return l+r;
    }
};
