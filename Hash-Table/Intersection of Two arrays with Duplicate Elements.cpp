//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<a.size();i++){
            mp[a[i]]++;
        }
        vector<int> ans;
        for(auto &e : b){
            if(mp[e]) { ans.push_back(e); mp[e]=0;}
        }
        return ans;
    }
};
