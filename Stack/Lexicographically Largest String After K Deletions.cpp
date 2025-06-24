class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        string ans;
       stack<char>st;
       for(auto i:s){
           while(k>0 and st.size() and st.top()<i){
               st.pop();
               k--;
           }
           st.push(i);
       }
       while(st.size()){
           if(k>0){
             k--;
           }
           else
           ans.push_back(st.top());
           st.pop();
       }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};
