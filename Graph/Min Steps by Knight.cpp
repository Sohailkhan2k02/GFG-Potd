class Solution {
  public:
        int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        vector<vector<int>> dir = {{-2,-1}, {-2, 1}, {2, -1}, {2, 1}, 
                                    {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
        
        int x1=knightPos[0], x2 = targetPos[0], y1=knightPos[1], y2 = targetPos[1];
        if(x1==x2 && y1 == y2)
        {
            return 0;
        }
        queue<vector<int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n,0));
        
        vis[x1-1][y1-1] = 1;
        q.push({x1, y1, 0});
        
        while(!q.empty())
        {
            vector<int> curr = q.front();
            q.pop();
            int x3 = curr[0], y3 = curr[1], dis = curr[2];
            
            for(int i=0;i<8;i++)
            {
                int x4 = x3+dir[i][0], y4 = y3+dir[i][1];
                if(isSafe(x4, y4, n) && !vis[x4-1][y4-1])
                {
                    if(x4 == x2 && y4 == y2)
                    {
                        return dis+1;
                    }
                    q.push({x4, y4, dis+1});
                    vis[x4-1][y4-1] = 1;
                }
            }
        }
        return -1;
    }
  
  private:
    bool isSafe(int x, int y, int n)
    {
        return (x>0 && y>0 && x<=n && y<=n);
    }
};
