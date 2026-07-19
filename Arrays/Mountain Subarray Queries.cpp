class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
          int n=arr.size();
      vector<int> inc(n);
      inc[n-1]=n-1;
      for(int i=n-2; i>=0; i--){
        if(arr[i] > arr[i+1]) inc[i]=i;
        else inc[i]=inc[i+1];
      }
      
      vector<int> dec(n);
      dec[0]=0;
      for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]) dec[i]=i;
        else dec[i]=dec[i-1];
      }
      
      
      vector<bool> ans;
      for(auto vq: queries){
        int l=vq[0], r=vq[1];
        if(inc[l] >= dec[r]) ans.push_back(true);
        else ans.push_back(false);
      }
      
      return ans;
    }
};
