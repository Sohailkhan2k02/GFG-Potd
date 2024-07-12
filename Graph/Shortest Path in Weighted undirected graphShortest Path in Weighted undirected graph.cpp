//T.C : O(n+m*log(n))
//S.C: O(n+m)
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>mpp[n+1];
        for(auto vec:edges){
            int u=vec[0],v=vec[1],w=vec[2];
            mpp[u].push_back({v,w});
            mpp[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        vector<int>dis(n+1,INT_MAX);
        dis[1]=0;
        vector<int>par(n+1,0);
        for(int i=0; i<=n; i++){
            par[i]=i;
        }
        
        while(!pq.empty()){
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            for(auto vec:mpp[u]){
                int v=vec.first,w=vec.second;
                if(d+w<dis[v]){
                    dis[v]=d+w;
                    pq.push({d+w,v});
                    par[v]=u;
                }
            }
        }
        
        if(dis[n]==INT_MAX) return {-1};
        vector<int>path;
        int node=n;
        while(par[node]!=node){
            path.push_back(node);
            node=par[node];
        }
        path.push_back(1);
        path.push_back(dis[n]);
        reverse(path.begin(),path.end());
        
        return path;
    }
};
