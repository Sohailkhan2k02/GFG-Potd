//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        int res=0,mnn=INT_MAX;
        for(int i=0; i<n; i++){
            mnn=min(mnn,prices[i]);
            res=max(res,prices[i]-mnn);
        }
        return res;
    }
};
