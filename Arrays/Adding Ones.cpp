class Solution {
  public:
    vector<int> update(int n, vector<int>& updates) {
        // code here
        vector<int>ans(n, 0);
                for(auto it : updates){
                    ans[it-1]++;
                }
                int sum = 0;
                for(int i = 0;i<n;i++){
                    sum+=ans[i];
                    ans[i] = sum;
                }
                return ans;
    }
};
