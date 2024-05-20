//T.C : O(logn)
//S.C : O(1)
#define ll long long
class Solution
{
	public:
	    ll power(ll x, ll n, ll mod){
	        if(n==0) return 1;
	        if(n<0) return 1/power(x,-n,mod);
	        if(n%2==1) return (x*power(x,n-1,mod))%mod;
	        ll temp=power(x*x%mod,n/2,mod)%mod;
	        return (temp+mod)%mod;
	    }
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    return power(x,n,M);
		}
};
