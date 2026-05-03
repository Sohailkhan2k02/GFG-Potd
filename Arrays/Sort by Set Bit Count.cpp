class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        vector<int> ans;
        int n = arr.size();
        map<int,vector<int>> mp;
        for(int i = 0;i < n;i++){
            int cnt = 0;
            int val = arr[i];
            while(val){
                if(val % 2 != 0)
                    cnt++;
                val/=2;
            }
            mp[cnt].push_back(arr[i]);
        }
        for (auto it = mp.rbegin(); it !=mp.rend(); it++) {
            for(auto it1 : it->second)
                ans.push_back(it1);
        }
        return ans;
    }
};
