//T.C : O(v+e)
//S.C : O(v+e)
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int n=adj.size();
        vector<int>res;
        vector<int>vis(n,0); vis[0]=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int node=q.front(); q.pop();
            res.push_back(node);
            for(auto vec:adj[node]){
                if(!vis[vec]){
                    q.push(vec);
                    vis[vec]=1;
                }
            }
        }
        return res;
    }
};
