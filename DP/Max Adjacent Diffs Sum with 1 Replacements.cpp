class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        long long keep = 0;

          long long replace = 0;

          for (int i = 1; i < arr.size(); i++) {
              long long newKeep = max(
                  keep + abs(arr[i] - arr[i - 1]),
                  replace + abs(arr[i] - 1)
              );

              long long newReplace = max(
                  keep + abs(1 - arr[i - 1]),
                  replace
              );

              keep = newKeep;
              replace = newReplace;
          }

          return (int)max(keep, replace);
    }
};
