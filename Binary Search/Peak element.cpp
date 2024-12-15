//T.C :O(logn)
//S.C :O(1)
class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
        int n =arr.size();
        int l=0, r=n-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(arr[mid]<arr[mid+1]){
                l =mid+1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};
