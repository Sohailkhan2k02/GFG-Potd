class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        // Code here
          vector<vector<int>>adj(V);
        vector<int>degree(V, 0);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            degree[it[1]]++;
            degree[it[0]]++;
        }
        queue<int>q;
        for(int i = 0;i<degree.size();i++){
            if(degree[i] > 1)continue;
            q.push(i);
        }
        vector<int>vec;
        while(q.size()){
            int size = q.size();
            vector<int>temp;
            while(size--){
                auto elem = q.front();
                temp.push_back(elem);
                q.pop();
                for(auto it : adj[elem]){
                    degree[it]--;
                    if(degree[it] == 1)q.push(it);
                }   
            }
            vec = temp;
        }
        return vec;
    }
};
