//T.C : O(v+e)
//S.C : O(v+e)
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void f(int node, vector<vector<int>>&adj, vector<int>&vis, vector<int>&res){
        vis[node]=1;
        res.push_back(node);
        for(auto vec:adj[node]){
            if(!vis[vec]){
                f(vec,adj,vis,res);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int>res;
        f(0,adj,vis,res);
        return res;
    }
};
