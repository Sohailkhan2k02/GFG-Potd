class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        // code here
        int n = arr.size();
        int ans = 0;
        int temp = 0;
        int start = 0;
        int end = m-1;
        
        for(int i=0;i<m;i++)temp+=arr[i];
        
        while(start<n){
            
            ans = max(ans,temp);
            
            end++;
            end%=n;
            temp += arr[end];
            temp-=arr[start];
            start++;
            
        }
        
        return ans;
    }
};
