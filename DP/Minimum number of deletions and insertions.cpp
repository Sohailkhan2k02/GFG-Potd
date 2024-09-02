//T.C : O(n*m)
//S.C : O(n*m)
class Solution{
	public:
	int f(int i, int j, string&s1, string& s2, int n, int m,vector<vector<int>>&dp){
	    if(i>=n && j<m){
	        return m-j;
	    }
	    if(j>=m && i<n){
	        return n-i;
	    }
	    if(i>=n && j>=m) return 0;
	    if(dp[i][j]!=-1) return dp[i][j];
	    if(s1[i]==s2[j]){
	        return dp[i][j]=f(i+1,j+1,s1,s2,n,m,dp);
	    }
	    else{
    	    int a=1+f(i,j+1,s1,s2,n,m,dp);
    	    int b=1+f(i+1,j,s1,s2,n,m,dp);
    	    return dp[i][j]=min(a,b);
	    }
	}
	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    int n=s1.size(),m=s2.size();
	    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	    return f(0,0,s1,s2,n,m,dp);
	    
	} 
};
