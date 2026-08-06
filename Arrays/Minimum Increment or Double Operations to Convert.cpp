class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int increments = 0;

        int maxValue = 0;

        for (int num : arr) {

            increments += __builtin_popcount(num);

            maxValue = max(maxValue, num);
        }

        int doubles = 0;

        while (maxValue > 1) {
            maxValue /= 2;
            doubles++;
        }

        return increments + doubles;
    }
};
