//T.C : O(n/2)
//S.C : O(1)
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            swap(arr[i++],arr[j--]);
        }
    }
};
