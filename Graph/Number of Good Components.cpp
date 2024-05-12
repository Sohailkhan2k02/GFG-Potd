//T.C : O(V+E)
//S.C : O(N)
class Solution {
  public:
  
    void dfs(vector<int>graph[], int node, vector<int>&vis, int &sz){
        vis[node] = 1;
        sz+=1;
        for(auto it: graph[node]){
            if(!vis[it]){
                dfs(graph,it, vis, sz);
            }
        }
        return;
    }
    
    bool ok(vector<int>graph[], int node, vector<int>&chk, int sz){
        chk[node]=1;
        if(graph[node].size() != sz-1) return false;
        for(auto adj: graph[node]){
            if(!chk[adj]){
                return ((graph[adj].size() == sz-1) && ok(graph,adj,chk,sz));
            }
        }
        return true;
    }
    
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int>graph[v+1];
        for(int i = 0; i<e; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(v+1,0);
        int fans = 0;
        for(int i = 1; i<=v; i++){
            if(!vis[i]){
                int sz = 0;
                dfs(graph,i,vis,sz);
                vector<int>chk(v+1,0);
                if(ok(graph,i,chk,sz)) fans+=1;
            }
        }
        return fans;
    }
};
