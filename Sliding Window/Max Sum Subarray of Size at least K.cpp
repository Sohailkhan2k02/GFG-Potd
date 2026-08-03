class Solution {
  public:
    int maxSumWithK(vector<int>& a, int k) {
        // code here
        int n=a.size();
        long long i=0,j=0;
        long long sum=0;
        long long maxsum=INT_MIN;
        long long last=0;
        while(j<n){
            sum+=a[j];
            if(j-i+1==k){
                maxsum=max(sum,maxsum);
            }
            else if(j-i+1>k){
                last+=a[i];
                i++;
                if(last<0){
                    sum-=last;
                    last=0;
                }
                maxsum=max(sum,maxsum);
            }
            j++;
        }
        return maxsum;
        
    }
};
