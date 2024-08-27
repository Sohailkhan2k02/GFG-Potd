//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
   static bool mycomp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int,int>mp;
        for(auto it:arr){
            mp[it]++;
        }
        vector<pair<int,int>>ans;
        for(auto it:mp){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(),ans.end(),mycomp);
        vector<int>res;
        for(auto it:ans){
            int time=it.second;
            while(time--)
            res.push_back(it.first);
        }
        return res;
    }
};
