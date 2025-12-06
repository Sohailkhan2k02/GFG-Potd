
//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int f(int i, int j, int arr[],vector<vector<long long>>&dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            return arr[i];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long t1=arr[i]+min(f(i+2,j,arr,dp), f(i+1,j-1,arr,dp));
        long long t2=arr[j]+min(f(i+1,j-1,arr,dp), f(i,j-2,arr,dp));
        
        return dp[i][j]=max(t1,t2);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        return f(0,n-1,arr,dp);
    }
};
