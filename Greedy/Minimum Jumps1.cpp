class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n=arr.size();
        int maxi=0;
        int choice=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,arr[i]+i);
            if(i==choice){
                choice=maxi;
                ans++;
            }
        }
        if(choice>=n-1){
            return ans;
        }
        return -1;
    }
};
