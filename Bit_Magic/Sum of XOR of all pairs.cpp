class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        long long ans = 0;
        int n = arr.size();
        int vec[32]{0};
        for(auto i: arr){
            int j = 0;
            while(i){
                if(i&1)vec[j]++;
                i = i>>1;
                j++;
            }
        }
        long long t = 1;
        for(int i =0  ;i<32 ; i++){
            ans+= t * (vec[i]) * (n- vec[i]);
            t = t<<1;
        }
        return ans;
        
    }
};
