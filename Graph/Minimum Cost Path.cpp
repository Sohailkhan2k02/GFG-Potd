//T.C : O(n*m)log(n*m)
//S.C : O(n*m)
class Solution
{
    public:
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({grid[0][0],0});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=grid[0][0];
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
        
            int i=node/m,j=node%m;
            for(int k=0; k<4; k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(d+grid[nrow][ncol]<dis[nrow][ncol]){
                        dis[nrow][ncol]=d+grid[nrow][ncol];
                        pq.push({d+grid[nrow][ncol],nrow*m+ncol});
                    }
                }
            }
        }
        
        return dis[n-1][m-1];
    }
};
