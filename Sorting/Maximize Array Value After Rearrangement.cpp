//T.C: O(nlogn)
//S.C: O(1)
class Solution {
  public:
    int Maximize(vector<int> arr) {
        // Complete the function
        sort(arr.begin(),arr.end());
       long long int mod=1e9+7;
       long long int ans=0;
       for(int i=0;i<arr.size();i++)
       ans+=(long long int)arr[i]*i,ans%=mod;
       return ans%mod;
    }
};
