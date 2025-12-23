class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        ios_base::sync_with_stdio(false);
        vector<int> res ;
        sort(arr.begin(),arr.end());
        
        for(auto query : queries){
            int a = query[0];
            int b = query[1];
            
            auto low = lower_bound(arr.begin(), arr.end(),a);
            auto high = upper_bound(arr.begin(), arr.end(),b);
            int cnt = high - low ;
            res.push_back(cnt);
        }
        return res ;
    }
};
