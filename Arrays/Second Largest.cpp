//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int mxx=-1,smxx=-1;
        for(int i=0; i<n; i++){
            if(arr[i]>mxx){
                smxx=mxx;
                mxx=arr[i];
            }
            else if(arr[i]>smxx && arr[i]!=mxx){
                smxx=arr[i];
            }
        }
        return smxx;
    }
};
