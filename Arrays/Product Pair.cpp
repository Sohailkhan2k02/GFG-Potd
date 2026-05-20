class Solution {
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        map<int,int>mpp;
        int r=0,n=arr.size();
        while(r<n-1){
            if(arr[r]!=0){
                if(target%arr[r]==0){
                    mpp[target/arr[r]]=1;
                }   
            }
            r++;
            if(mpp[arr[r]]==1){
                return true;
            }
            
        }
        return false;
    }
};
