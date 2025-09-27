class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> prefix(n+2, 0);
        int ans = 0;
        
        for(int i=0;i<=(n-k);i++){
            if(i>0)
              prefix[i] += prefix[i-1];
              
            if(arr[i]==0 && prefix[i]%2==0){
                prefix[i]++;
                prefix[i+k]--;
                ans++;
            }
            
            if(arr[i]==1 && prefix[i]%2==1){
                prefix[i]++;
                prefix[i+k]--;
                ans++;
            }
        }
        
        
        for(int i=n-k+1;i<n;i++){
            prefix[i] += prefix[i-1];
            if(arr[i]==0 && prefix[i]%2==0)
              return -1;
            if(arr[i]==1 && prefix[i]%2==1)
              return -1;
        }
        
        return ans;
    }
};
