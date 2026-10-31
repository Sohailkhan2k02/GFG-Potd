class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        int totalPackage = 0;

                for(int i = 0; i < min(totalTime, (int)arr.size()); i++) {
                    totalPackage += arr[i];
                }

                int package = totalPackage;
                for(int i = totalTime; i < arr.size(); i++) {
                    package += arr[i] - arr[i - totalTime];

                    totalPackage = max(package, totalPackage);
                }

                return totalPackage;
    }
};
