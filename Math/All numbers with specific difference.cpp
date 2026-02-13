class Solution {
    private:
        int sumOfDigits(int x){
            int sum = 0;
            while(x > 0){
                sum += x % 10;
                x /= 10;
            }
            return sum;
        }
  public:
    int getCount(int n, int d) {
        int low = 1, high = n,ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(mid - sumOfDigits(mid) >= d){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans != -1 ? n - ans + 1 : 0;
    }
};
