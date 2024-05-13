//T.C : O(V+E)
//S.C : O(N)

class Solution {
  public:
    void dfs(int i, unordered_map<int,vector<int>>&mpp, int &e_cnt, int &v_cnt, vector<int>&vis){
        vis[i]=1;
        v_cnt++;
        e_cnt+=mpp[i].size();
        
        for(auto vec:mpp[i]){
            if(!vis[vec]){
                dfs(vec,mpp,e_cnt,v_cnt,vis);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int n, vector<vector<int>> &edges) {
        // code here
        unordered_map<int,vector<int>>mpp;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }
        
        vector<int>vis(n+1,0);
        int ans=0;
        for(int i=1; i<=n; i++){
            // for every dfs call we will make new edge count and new v_count
            int e_cnt=0;
            int v_cnt=0;
            if(!vis[i]){
                dfs(i,mpp,e_cnt,v_cnt,vis);
                
                if(e_cnt==(v_cnt*(v_cnt-1))){
                    ans++;
                }
            }
        }
        return ans;
        
        
    }
};
