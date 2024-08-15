//T.C: O(n)
//S.C: O(n)
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int f(int n, int x, int y, int z,vector<int>&dp){
        if(n==0) return 0;
        if(n<0) return INT_MIN;
        if(dp[n]!=-1) return dp[n];
        int a=1+f(n-x,x,y,z,dp);
        int b=1+f(n-y,x,y,z,dp);
        int c=1+f(n-z,x,y,z,dp);
        return dp[n]=max({a,b,c});
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        int res=f(n,x,y,z,dp);
        if(res<0) return 0;
        return res;
    }
};
