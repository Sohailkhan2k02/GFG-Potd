class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<pair<int, int>> dp (n, {0, 0});
        dp[0].first = 1;
        dp[0].second = arr[0];
        int maxLen = 1;
        int sum = arr[0];
        for(int i = 1; i < n; i++){
            int currLen = 1;
            int currVal = arr[i];
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    int newLen = dp[j].first + 1;
                    if(newLen > currLen){
                        currLen = newLen;
                        currVal = dp[j].second + arr[i];
                    }else if(newLen == currLen){
                        currVal = min(currVal, dp[j].second + arr[i]);
                    }
                }
            }
            dp[i].first = currLen;
            dp[i].second = currVal;
            if(maxLen < currLen){
                maxLen = currLen;
                sum = currVal;
            }else if(maxLen == currLen){
                sum = min(sum, currVal);
            }
        }
        
        
        int totalSum = 0;
        for(auto &e : arr){
            totalSum += e;
        }
        return totalSum - sum;
    }
};
