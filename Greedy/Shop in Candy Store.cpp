class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        vector<int>ans;
        sort(prices.begin(), prices.end());
        int cnt = 0, i = 0, mini = 0;
        while(cnt < prices.size()){
            cnt+=k;
            cnt++;
            mini += prices[i++];
        }
        cnt = 0;
        i = prices.size()-1;
        int maxi = 0;
        while(cnt < prices.size()){
            cnt+=k;
            cnt++;
            maxi += prices[i--];
        }
        return {mini, maxi};
    }
};
