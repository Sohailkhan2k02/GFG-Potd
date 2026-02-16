class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        sort(arr.begin(), arr.end());
        for(int i = 1;i<arr.size();i++){
            if(arr[i-1][1]>arr[i][0])return false;
        }
        return true;
    }
};
