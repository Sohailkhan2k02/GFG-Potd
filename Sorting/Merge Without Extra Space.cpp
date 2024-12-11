//T.C : O(n+m)
//S.C : O(1)
class Solution {
  public:
    void swapifgreater(vector<int>&arr1, vector<int>&arr2, int i, int j) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
    }
    void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n=arr1.size(),m=arr2.size();
        int len=n+m;
        int gap=len/2+len%2;
        while(gap>0){
            int i=0,j=i+gap;
            while(j<len){
               if(i<n && j>=n){
                 swapifgreater(arr1,arr2,i,j-n);
                }
                else if(i>=n && j>=n){
                    swapifgreater(arr2,arr2,i-n,j-n);
                }
                else if(i<n && j<n){
                    swapifgreater(arr1,arr1,i,j);
                }
                i++,j++;
            }
                if(gap==1) break;
                gap=gap/2+gap%2;
        }
    }
};
