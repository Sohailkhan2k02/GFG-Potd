//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
        int n=arr.size();
          for(int i=0; i<n; i++){
        arr[i]= A * arr[i] * arr[i] + B * arr[i] + C;
    }
    sort(arr.begin(), arr.end());
    return arr;
    }
};
