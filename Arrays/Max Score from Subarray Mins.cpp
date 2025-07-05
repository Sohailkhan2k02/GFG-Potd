//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long sum=0,maxi=INT_MIN;
        for(int i=1; i<n; i++){
            sum=arr[i-1]+arr[i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
