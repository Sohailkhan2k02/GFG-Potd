class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        vector<vector<int>>adj(n);
        vector<int>inDegree(n);
        for(int i = 0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i = 0;i<inDegree.size();i++){
            if(inDegree[i])continue;
            q.push(i);
        }
        int cnt = 0;
        while(q.size()){
            auto elem = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[elem]){
                inDegree[it]--;
                if(inDegree[it])continue;
                q.push(it);
            }
        }
        return cnt == n;
    }
};
