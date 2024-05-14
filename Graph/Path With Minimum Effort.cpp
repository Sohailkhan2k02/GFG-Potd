//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &grid) {
        // code here
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            
            if(i==n-1 && j==m-1){
                return dis[i][j];
            }
            
            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};
            for(int k=0; k<4; k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int maxdiff=max(abs(grid[i][j]-grid[nrow][ncol]),diff);
                    if(maxdiff<dis[nrow][ncol]){
                        dis[nrow][ncol]=maxdiff;
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        
        return -1;
    }
};
