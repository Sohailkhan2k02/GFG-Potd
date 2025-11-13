class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        auto f=[&](auto && f,int i,int j)->int{
            
           
            
            if(i==n1 && j==n2 && i+j==n3)
            return 1;
            
           if(dp[i][j]!=-1)
           return dp[i][j];
         int x=0,y=0;
           if(i<n1 && s1[i]==s3[i+j])
           {
               x = f(f,i+1,j);
               
           }
           
           if(j<n2 && s2[j]==s3[i+j])
           {
                y= f(f,i,j+1);
             
           }
           
           return dp[i][j] =x||y;
        };
        return f(f,0,0);
    
    }
};
