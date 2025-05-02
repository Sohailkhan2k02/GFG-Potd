//T.C : O(nlogn)
//S.C : O1)
// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
       
       int l =0,r=n-1,res=n-1;
       
       while(l<=r){
           int mid = l + (r-l)/2;
           if(mid<n-1 && arr[mid]>arr[mid+1]) {
               res=mid;
               r=mid-1;
           }
           else l=mid+1;
       }
       
       return arr[res];
    }
};
