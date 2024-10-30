//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        using ll=long long;
        int n=arr.size();
        map<ll,ll>mpp;
        for(auto i:arr){
            mpp[i]++;
        }
        ll cnt=0;
        for(int i=0; i<n; i++){
            if(mpp.find(arr[i]+k)!=mpp.end()){
                cnt+=mpp[arr[i]+k];
            }
            if(k!=0 && mpp.find(arr[i]-k)!=mpp.end()){
                cnt+=mpp[arr[i]-k];
            }
            mpp[arr[i]]--;
        }
        return cnt;
    }
};
