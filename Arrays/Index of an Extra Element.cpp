//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int i=0,j=0;
        while(i<n || j<n-1){
            if(arr1[i]==arr2[j]){
                i++;
                j++;
            }
            else{
                return i;
            }
        }
        return -1;
    }
};
