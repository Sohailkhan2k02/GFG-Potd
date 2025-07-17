class Solution {
  public:
  void fact(int n,map<int,int>&mp){
        int ct = 0;
        while (n%2 == 0) {
            ct++;
            n /= 2;
        }
        if(ct > 0){
            mp[2]+= ct;
        }
        for (int i = 3;i*i <= n;i+=2) {
            ct = 0;
            while (n%i == 0) {
                ct++;
                n /= i;
            }
            if(ct > 0)mp[i]+= ct;
        }
        if (n > 2){
            mp[n] += 1;
        }
    }
    int maxKPower(int n, int k) {
        map<int,int>mp1;
        map<int,int>mp2;
        fact(k,mp1);
        for(int i=2;i<=n;i++){
            fact(i,mp2);
        }
        int ans = INT_MAX;
        for(auto pai:mp1){
            // Maximum number of k's that can be formed
            ans = min(ans,mp2[pai.first]/pai.second);
        }
        return ans;
    }
};
