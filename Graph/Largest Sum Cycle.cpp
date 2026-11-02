class Solution {
  public:
  void make(int s,vector<int>&vis,vector<int>&dis,int&ans,vector<vector<int>>&adj,int dist,vector<int>&stack)
    {
        if(vis[s]==1)
        {
            if(stack[s]==1)
            {
            int x=dist-dis[s];
            ans=max(ans,x);
            } 
            return ;
        }
        vis[s]=1;
        stack[s]=1;
        int p=dis[s];
        dis[s]=dist;
        for(int i=0;i<adj[s].size();i++)
        {
            int v=adj[s][i];
            make(v,vis,dis,ans,adj,dist+s,stack);
        }
        stack[s]=0;
        dis[s]=p;
    }
    int largestSumCycle(vector<int>& Edge) {
        // code here
        int N=Edge.size();
        vector<vector<int>>adj(N);
              for(int i=0;i<Edge.size();i++)
              {
                  if(Edge[i]>=0)
              {
              adj[i].push_back(Edge[i]);
                  }
              }
              vector<int>vis(N,0);
              vector<int>dis(N,0);
              vector<int>stack(N,0);
              int ans=-1;
              for(int i=0;i<N;i++)
              {
                  if(vis[i]==0)
                  {
                      make(i,vis,dis,ans,adj,0,stack);      
                  }
              }
              return ans;
    }
};
