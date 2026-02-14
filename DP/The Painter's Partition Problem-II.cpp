class Solution {
  public:
    bool check(vector<int>&arr, int k, int mid){
      int sum=0, pk=0;
      for(auto &b: arr){
          sum+=b;
          if(sum>mid){
              sum=b;
              pk++;
          }
          if(pk==k){return false;}
      }
      return true;
  }
    int minTime(vector<int>& arr, int k) {
        int l=*max_element(arr.begin(), arr.end()), r=accumulate(arr.begin(), arr.end(), 0L);
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(arr, k, mid)){ans=mid; r=mid-1;}
            else{l=mid+1;}
        }
        return ans;
    }
};
