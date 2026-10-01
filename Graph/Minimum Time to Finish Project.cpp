class Solution {
  public:
    int minTime(vector<int> &duration, vector<vector<int>> &dependencies) {
        // code here
        vector<int>order;
        int n=duration.size();
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto e:dependencies){
            adj[e[0]].push_back(e[1]);
            indeg[e[1]]++;
        }
        queue<int>q;
        vector<int>comp(n,INT_MIN);
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
                comp[i]=duration[i];
                
                
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indeg[it]--;
                comp[it]=max(duration[it]+comp[node],comp[it]);
                if(indeg[it]==0){
                    q.push(it);
                }
            }
            
            
        }
       
       for(int i=0;i<n;i++){
           if(indeg[i]>0){
               return -1;
           }
       }
        int maxtime=0;
        for(int i=0;i<n;i++){
            
            maxtime=max(maxtime,comp[i]);
        }
        return maxtime;
    }
};
