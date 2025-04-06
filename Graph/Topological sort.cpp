//T.C : O(v+e)
//S.C : O(v+e)
class Solution {
  public:
    void solve(vector<vector<int>>& adj, vector<bool>& visited, int src, stack<int>& st){
        visited[src] = true;
        
        for(auto nbr : adj[src]){
            if(!visited[nbr]){
                solve(adj, visited, nbr, st);
            }
        }
        st.push(src);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        vector<bool> visited(V, false);
        vector<int> ans;
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                solve(adj, visited, i, st);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
