class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) mp[arr[i]]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans(k);
        for(int i = 0; i < k; i++) {
            ans[k - i - 1] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};
