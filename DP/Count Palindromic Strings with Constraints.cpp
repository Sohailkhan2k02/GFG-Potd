class Solution {
  public:
    int palindromicStrings(int n, int k) {
        // code here
        long long mod = 1e9+7;
        vector<long long> vec(k+1,1);
        int count=k;
        for(int i=1;i<=k;i++){
            vec[i] = (vec[i-1]%mod*(count--)%mod)%mod; 
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            int index = (i+1)/2;
            if(index<=k){
                ans = (ans%mod +  vec[index]%mod)%mod;
            }
            else{
                break;
            }
        }
        return ans;
    }
};
