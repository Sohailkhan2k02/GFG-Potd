class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>ans;
        vector<vector<int>>adj(V);
        vector<int>indegree(V, 0);
        queue<int>q;
        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i = 0;i<V;i++){
            if(!indegree[i])q.push(i);
        }
        while(q.size()){
            auto elem = q.front();
            q.pop();
            ans.push_back(elem);
            for(auto it : adj[elem]){
                indegree[it]--;
                if(!indegree[it])q.push(it);
            }
        }
        return ans;
    }
};
