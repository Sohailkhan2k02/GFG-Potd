//T.C : O(n!*n)
//S.C : O(n)
class Solution {
  public:
  void f(int ind,string &s,vector<string>&res,int n){
      if(ind>=n){
          return;
      }
      res.push_back(s);
      for(int i=ind; i<n; i++){
          swap(s[i],s[ind]);
          f(ind+1,s,res,n);
          swap(s[i],s[ind]);
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        int n=s.size();
        vector<string>res;
        f(0,s,res,n);
        set<string>st(res.begin(),res.end());
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};
