//T.C : O(n*k)
//S.C : O(k)
class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<int>> curr(k+2, vector<int>(2, 0));
        vector<vector<int>> next(k+2, vector<int>(2, 0));

        for(int i = n-1; i >= 0; i--){
            for(int limit = k; limit >= 0; limit--){
                for(int buy = 0; buy <= 1; buy++){
                    int ans = 0;
                    int include = 0;
                    int exclude = 0;
                    if(limit < k){
                        if(buy){
                            include = -1*prices[i] + next[limit][false];
                            exclude =  next[limit][true];  
                        }
                        else{
                            include = prices[i] + next[limit+1][true];   
                            exclude = next[limit][false];   
                        }
                    }
                
                    ans = max(include, exclude);
                    curr[limit][buy] = ans;
                }
            }
            next = curr;
        }

        return next[0][1];
    }
};
