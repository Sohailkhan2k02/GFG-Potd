//T.C : O(logn)
//S.C : O(1)
class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        int n=arr.size();
        int l=0,h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            int cnt=arr[m]-m-1;
            if(cnt<k){
                l=m+1;
            }
            else h=m-1;
        }
        return h+k+1;
    }
};
