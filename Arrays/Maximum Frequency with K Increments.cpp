class Solution {
  public:
    int maxFrequency(vector<int>& nums, int k) {
        // code here
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int j=0;
        long long int res=0;
        for(int i=0;i<n;i++){
            res+= nums[i];
            long long x=(i+1);
            long long temp=nums[i]*(x);

            if((temp-res)<=k){

            }else{
                while(res>k && j<i){
                    long long y=(i-j+1);
                    long long t=nums[i]*y;
                    if(t-res<=k) break;
                    res-= nums[j];
                    j++;
                }
            }
            ans=max(ans,(i-j+1));   
        }
        
        return ans;
    }
};
