class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        if(s.size()%k!=0){return 0;}
        unordered_map<string, int>st; int minn=INT_MAX;
        for(int i=0; i<s.size(); i+=k){
            string ss=s.substr(i,k);
            st[ss]++;
            if(st.size()==3){return 0;}
        }
        for(auto &b: st){minn=min(minn, b.second);}
        if(minn==1 or st.size()==1){return 1;}
        return 0;
    }
};
