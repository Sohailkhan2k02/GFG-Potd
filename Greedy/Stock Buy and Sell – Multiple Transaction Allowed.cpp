//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int maximumProfit(vector<int> &price) {
        // code here
        int n=price.size();
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (price[i] > price[i - 1])
                profit += price[i] - price[i - 1];
        }
        return profit;
    }
};
