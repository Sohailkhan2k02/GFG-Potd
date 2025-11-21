class Solution {
  public:
     int shortestPath(int n, int a, int b, vector<vector<int>> &edges) {
        // code here
        vector<vector<long long>>dp(n,vector<long long>(2,INT_MAX));
        priority_queue<tuple<long long,long long,long long>,vector<tuple<long long,long long,long long>>,greater<>>pq;
        pq.push({0,0,a});
        vector<vector<tuple<long long,long long,long long>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            long long x=edges[i][0];
            long long y=edges[i][1];
            long long c1=edges[i][2];
             long long c2=edges[i][3];
            adj[x].push_back({y,c1,c2});
            adj[y].push_back({x,c1,c2});
        }
         dp[a][0]=0;
         dp[a][1]=0;
        while(!pq.empty())
        {
            auto x=pq.top();
             pq.pop();
        long long cost=get<0>(x);
          long long   flag=get<1>(x);
            long long node=get<2>(x);
            for(auto itr:adj[node])
            {
               long long  j=get<0>(itr);
               long long  c1=get<1>(itr);
                long long c2=get<2>(itr);
                if(flag==0)
                {
                    long long ans1=cost+c1;
                    long long ans2=cost+c2;
                    if(ans2<dp[j][1])
                    {
                        dp[j][1]=ans2;
                        pq.push({ans2,1,j});
                    }
                    if(ans1<dp[j][0])
                    {
                        dp[j][0]=ans1;
                        pq.push({ans1,0,j});
                    }
                
                }
                else
                {
                    long long ans1=cost+c1;
                    if(ans1<dp[j][1])
                    {
                        dp[j][1]=ans1;
                        pq.push({ans1,1,j});
                    }
                    
                }
            }
        }
        int x=min(dp[b][0],dp[b][1]);
        if(x>=INT_MAX)
        {
            return -1;
        }
        return x;
       
        
        
        
    
    }
};
