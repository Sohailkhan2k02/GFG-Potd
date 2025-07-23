//User function template for C++

class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
        // Your code goes here
        long long int sm=0,mod=1e9+7;
        for(long long int i=0; i<n; i++){
            sm+=((i+1)*(n-i)*a[i])%mod;
        }
        return sm%mod;
    }
};
