using ll = long long;
constexpr ll MOD = 1000000007;
vector<ll> fact(200001);

static auto init = [](){
    fact[0] = 1;
    for(int i = 1;i<=200000;i++)
    {
        fact[i] = ((fact[i-1])*i)%MOD;
    }
    return 0;
}();

class Solution {
  public:
  ll power(ll a, ll b)
  {
      if(b == 0)
      return 1LL;
      
      ll res = 1LL;
      ll half = power(a,b/2)%MOD;
      
      res = (half*half)%MOD;
      if(b&1) res = (a*res)%MOD;
      return res;
  }
    int computeValue(int n) {
        // code here
        ll numerator = fact[2*n];
        ll denominator = (fact[n] * fact[n])%MOD;
        ll ans = (numerator * power(denominator,MOD - 2))%MOD;
        
        return (int) ans;
    }
};
