// User function Template for C++

class Solution {
  public:
  const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        unordered_map<int,vector<pair<int,int>>>mpp;
        for(auto vec:roads){
            int u=vec[0];
            int v=vec[1];
            int t=vec[2];
            mpp[u].push_back({v,t});
            mpp[v].push_back({u,t});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<long long>cnt(n,0);
        vector<long long>dis(n,LONG_MAX);
        dis[0]=0;
        cnt[0]=1;
        while(!pq.empty()){
            long long time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto vec:mpp[node]){
                int adjnode=vec.first;
                long long t=vec.second;
                if(t+time<dis[adjnode]){
                    dis[adjnode]=t+time;
                    pq.push({t+time,adjnode});
                    cnt[adjnode]=cnt[node];
                }
                else if(dis[adjnode]==t+time){
                    cnt[adjnode]=(cnt[node]+cnt[adjnode])%mod;
                }
            }
        }
        return cnt[n-1]%mod;
    }
};
