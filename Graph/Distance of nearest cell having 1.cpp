class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>res(n,vector<int>(m,-1));
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j]==1){
	               q.push({{i,j},0});
	               vis[i][j]=1;
	               res[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int u=q.front().first.first;
	        int v=q.front().first.second;
	        int t=q.front().second;
	        q.pop();
	        
	        res[u][v]=t;
	        
	        int delrow[]={-1,0,1,0};
	        int delcol[]={0,1,0,-1};
	        for(int k=0; k<4; k++){
	            int nrow=u+delrow[k];
	            int ncol=v+delcol[k];
	            
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=1){
	                q.push({{nrow,ncol},t+1});
	                vis[nrow][ncol]=1;
	            }
	        }
	    }
	    return res;
	    
	}
};
