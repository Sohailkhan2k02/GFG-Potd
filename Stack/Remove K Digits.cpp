// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top()>s[i] && k>0){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        if(st.empty()){
            return "0";
        }
        while(k--){
            st.pop();
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        if(i==ans.size()) return "0";
        return ans.substr(i);
    }
};
