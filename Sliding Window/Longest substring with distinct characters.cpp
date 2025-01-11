//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int sz=0;
        int l=0;
        unordered_map<char, int> m;
        for(int r=0; r<s.size(); r++){
            if(m.find(s[r]) != m.end()){
                int a = m.size();
                sz = max(sz,a);
                l = m[s[r]]+1;
                r=l;
                m.clear();
                m[s[r]] = r;
                continue;
            }
                m[s[r]] = r; 
                int a = m.size();
                sz = max(sz, a);
        }
        return sz;
    }
};
