//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(int i = 0 ; i<arr.size() ; i++){
            string s = arr[i];
            sort(s.begin() , s.end());
            mp[s].push_back(arr[i]);
        }
        
        for(auto c:mp){
            if(c.second.size()>0)
            ans.push_back(c.second);
        }
        return ans;
    }
};
