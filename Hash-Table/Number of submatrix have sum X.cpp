class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = (int)mat.size();
        int m = (int)mat[0].size();
        
        vector<vector<int>>prefix(n+1,vector<int>(m+1,0));
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                prefix[i][j] = mat[i-1][j-1]+ prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
                
            }
        }
        int count = 0;
        for(int k = 1 ;k <=min(n,m);k++)
        {
            for(int i =1;(i+k-1)<=n;i++)
            {
                for(int j = 1;(j+k-1)<=m;j++)
                {
                    int s= prefix[i+k-1][j+k-1] 
                    - prefix[i+k-1][j-1] 
                    - prefix[i-1][j+k-1] 
                    + prefix[i-1][j-1];
                    
                    if(s==x)
                    count++;
                }
            }
        }
        
        return count;
    }
};
