//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
         int n = arr.size();
         vector<int> ans(2);
        int i = 0;
        int j = 0;
        int sum = 0;
        
        while(j < n){
            sum += arr[j];
           
            while(sum > target){
                sum -= arr[i];
                i++;
            }
            if(sum == target){
                ans[0] = i+1;
                ans[1] = j+1;
                return ans;
            }
            j++;
        }
        return {-1};
    }
};
