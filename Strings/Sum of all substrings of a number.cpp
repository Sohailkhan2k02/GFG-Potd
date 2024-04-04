//T.C : O(n)
//S.C : O(1)
class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    const int mod=1e9+7;
    long long sumSubstrings(string s){
        int n=s.size();
        long long res=0;
        long long sum=0;
        for(int i=0; i<n; i++){
            int cnt=s[i]-'0';
            sum=(sum*10+(cnt*(i+1)))%mod;
            res=(res+sum)%mod;
        }
        return res;
    }
};
