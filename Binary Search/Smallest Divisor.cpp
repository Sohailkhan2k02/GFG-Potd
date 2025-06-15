//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        int low = 1;
        int maxE = *max_element(arr.begin(), arr.end());
        int high = maxE + k;
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            int count = 0;
            for(auto &e : arr){
                count += ceil((double)e/mid);
            }
            if(count <= k){
                ans = min(mid, ans);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
