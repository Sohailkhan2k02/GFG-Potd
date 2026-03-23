class Solution {
  public:
    int count[10001] = {0};
    void solve(int i,vector<vector<int>> &v,int &maxi,int &cnt,unordered_map<int,int> &mp){
         count[i]++;
         cnt++;
         mp[i] = cnt;
         vector<int> w = v[i];
         for(int j = 0;j<w.size();j++){
              if(count[w[j]] == 0){
                  solve(w[j],v,maxi,cnt,mp);
              }
              else{
                  maxi = max(maxi,cnt-mp[w[j]]+1);
              }
         }
         count[i]--;
         cnt--;
         mp.erase(i);
         return ;
    }
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> v(V);
        for(int i = 0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            v[a].push_back(b);
        }
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        int cnt = 0;
        for(int i = 0;i<V;i++){
            solve(i,v,maxi,cnt,mp);
        }
        if(maxi == INT_MIN || maxi < 2){
            return -1;
        }
        return maxi;
    }
};
