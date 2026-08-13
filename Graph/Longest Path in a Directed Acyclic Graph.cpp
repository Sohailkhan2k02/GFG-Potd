class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<int>ans(V,INT_MIN);
        ans[src]=0;
        for(int i=1;i<=V-1;i++){
            for(auto &it:edges){
                int a=it[0];
                int b=it[1];
                int c=it[2];
                if(ans[a]!=INT_MIN&& ans[a]+c>ans[b]){
                    ans[b]=ans[a]+c;
                }
            }
        }
        return ans;
    }
};
