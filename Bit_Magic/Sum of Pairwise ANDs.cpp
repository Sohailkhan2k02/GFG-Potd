class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long sum=0;
        for(int i=0;i<32;i++){
            long long cnt=0;
            
            long long num= 1<<i;
            
            for(int j=0;j<n;j++){
                
                if(arr[j] & num){
                    cnt++;
                    
               }
            }
            sum+= (cnt*(cnt-1)/2)*num;
          }
        return sum;
    }
};
