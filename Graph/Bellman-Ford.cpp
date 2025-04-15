//T.C : O(n*n)
//S.C : O(n)
class Solution {
  public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dis(n,1e8);
        dis[src]=0;
        // ONLY FOR N-1 TIMES ITERATIONS
        for(int i=0; i<n-1; i++){
            for(auto vec:edges){
                int u=vec[0];
                int v=vec[1];
                int wt=vec[2];
                
                if(dis[u]!=1e8 && dis[u]+wt<dis[v]){
                    dis[v]=dis[u]+wt;
                }
            }
        }
        
        // NOW NTH RELAXATION TO CHECK NEGATIVE CYCLE
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            if(dis[u]!=1e8 && dis[u]+wt<dis[v]){
                return {-1};
            }
        }
    
        return dis;
    }
};
