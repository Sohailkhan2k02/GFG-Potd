//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        using ll=long long;
        sort(arr.begin(),arr.end());
        ll sum=0;
        int i=0,j=n-1;
        while(i<j){
            sum+=abs(arr[i++]-arr[j--]);
        }
        return 2*sum;
    }
};
