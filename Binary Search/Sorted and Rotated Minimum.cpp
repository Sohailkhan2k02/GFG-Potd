//T.C : O(logn)
//S.C : O(1)
class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int n=arr.size();
        int l=0,h=n-1;
        int res=0;
        while(l<h){
            int m=l+(h-l)/2;
            if(arr[m]>arr[h]){
                l=m+1;
            }
            else{
                h=m;
            }
        }
        return arr[l];
    }
};
