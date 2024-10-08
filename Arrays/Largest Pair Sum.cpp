//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int mxx=0,smxx=0;
        for(int i=0; i<n; i++){
            if(arr[i]>mxx){
                smxx=mxx;
                mxx=arr[i];
            }
            else if(arr[i]>smxx && arr[i]<mxx){
                smxx=arr[i];
            }
        }
        return mxx+smxx;
    }
};
