class Solution {
  public:
 int NumberOfDonuts(int t, vector<int>& ranks){
      long long donuts = 0;
      for(int i=0;i<ranks.size();i++){
          donuts += (sqrt(1 + 8.0 * t / ranks[i]) - 1) / 2;
      }
      return donuts;
  }
    int minTime(vector<int>& ranks, int n) {
        // code here
        long long low = 0;
        long long high = 1LL * n * (n + 1) / 2 * (*min_element(ranks.begin(), ranks.end()));
        long long ans = high;
        while(low<=high){
            long long mid = low+ (high-low)/2;
            if(NumberOfDonuts(mid, ranks)>=n){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
