//T.C : O(n*n)
//S.C : O(n*n)
class Solution
{
    public:
        //User function Template for C++
        int f(int i, int n, int curr, vector<int> &v, vector<vector<int>> &dp) {
            if(i==n || curr==4) return 0;
            if(dp[i][curr]!=-1) return dp[i][curr];
            
            int pick=0, notpick=0;
            if(curr%2==0) pick=-v[i]+ f(i+1,n,curr+1,v,dp);
            if(curr%2==1) pick=v[i]+ f(i+1,n,curr+1,v,dp);
            notpick= f(i+1,n,curr,v,dp);
            
            return dp[i][curr] =max(pick,notpick);
        }
        
        int maxProfit(vector<int>& prices){
            int n=prices.size();
            vector<vector<int>> dp(n,vector <int> (4,-1));
            return f(0,n,0,prices,dp);
        }
};
