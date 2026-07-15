class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n=arr.size();
      
      vector<int> left(n, 0);
      vector<int> right(n, n-1);
      
      for(int i=1; i<n; i++){
        if(arr[i] >= arr[i-1]) left[i]=left[i-1];
        else left[i]=i;
      }
      
      for(int i=n-2; i>=0; i--){
        if(arr[i] >= arr[i+1]) right[i]=right[i+1];
        else right[i]=i;
      }
      
      int ans=0;
      for(int i=0; i<n; i++){
        ans=max(ans, right[i]-left[i]+1);  
      }
      
      
      return ans;
    }
};
