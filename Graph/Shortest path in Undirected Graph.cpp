//T.C : O((E+V)logV)
//S.C : O(N)
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=1;
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(dis[node]+wt<dis[v]){
                    dis[v]=dis[node]+wt;
                    pq.push({dis[v],v});
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(dis[i]==INT_MAX){
                dis[i]=-1;
            }
        }
        
        return dis;
    }
};
