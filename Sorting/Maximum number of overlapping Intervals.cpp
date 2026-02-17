class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        int maxi=INT_MIN;
        for(vector<int> v:arr){
            if(maxi<v[1])maxi=v[1];
        }
        vector<int>mp(maxi+1,0);
        for (auto &interval : arr) {
            mp[interval[0]-1]++;      
            mp[interval[1]]--;  
        }
    
        int ans = 0, count = 0;
        for (auto p : mp) {
            count += p;
            ans = max(ans, count);
        }
        return ans;
    }
};
