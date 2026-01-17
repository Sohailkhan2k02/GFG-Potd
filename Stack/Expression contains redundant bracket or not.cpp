class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char> st;
        //int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')'){
                int count=0;
                while(st.top()!='('){
                    st.pop();
                    count++;
                }
                st.pop();
                if(count==0||count==1)return true;
            }
            else{
                st.push(s[i]);
            }
        }
        return false;
    }
};
