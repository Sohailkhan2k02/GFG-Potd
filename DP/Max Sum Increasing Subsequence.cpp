class Solution{
		

	public:
	int f(int i, int j, int arr[], int n, vector<vector<int>>&dp){
	    if(i>=n){
	        return 0;
	    }
	    if(dp[i][j+1]!=-1) return dp[i][j+1];
	    
	    int nottake = f(i+1,j,arr,n,dp);
	    int take =0;
	    if(j==-1 || arr[i]>arr[j]){
	        take = arr[i]+f(i+1,i,arr,n,dp);
	    }
	    return dp[i][j+1] = max(take, nottake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    //vector<vector<int>>dp(n, vector<int>(n+1,-1));
	    //return f(0,-1,arr,n,dp);
	    vector<int>dp(n,0);
	    int ans = INT_MIN;
	    for(int i=0; i<n; i++){
	        dp[i]=arr[i];
	    }
	    for(int i=0; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(arr[i]>arr[j]){
	                dp[i] = max(dp[j]+arr[i],dp[i]);
	            }
	        }
	        ans = max(ans, dp[i]);
	    }
	    
	    return ans;
	}  
};
