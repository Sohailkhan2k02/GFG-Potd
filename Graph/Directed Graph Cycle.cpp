//T.C : O(v+e)
//S.C : O(v+e)
class Solution {
  public:
    bool fun(int i, vector<vector<int>> &adj, vector<bool> &vis1, vector<bool> &vis2){
        vis1[i] = true;
        vis2[i] = true;
        
        for(auto x : adj[i]){
            if(!vis1[x]){
                if(fun(x, adj, vis1, vis2))
                    return true;
                
            }
            else if(vis2[x])
                return true;
        }
        
        vis2[i] = false;
        return false;
    }
    
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto z : edges){
            adj[z[0]].push_back(z[1]);
        }
        
        vector<bool> vis1(V, false);
        vector<bool> vis2(V, false);
        
        for(int i=0;i<V;i++){
            if(!vis1[i] && fun(i, adj, vis1, vis2))
                return true;
            
        }
        return false;
    }
};
