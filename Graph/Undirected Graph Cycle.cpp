//T.C : O(v+e)
//S.C : O(v+e)
class Solution {
  public:
bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adj[V];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>vis(V, 0);
        vector<int>par(V, -1);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    
                    for(auto &ngbr:adj[node]){
                        if(!vis[ngbr]){
                            vis[ngbr]=1;
                            par[ngbr]=node;
                            q.push(ngbr);
                        }else if(par[node]!=ngbr) return 1;
                    }
                }
            }
        }
        return 0;
    }
};
