//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ind=0;
        for(int i=0; i<n; i++){
            if(arr[i]!=0){
                arr[ind++]=arr[i];
            }
        }
        while(ind<n){
            arr[ind++]=0;
        }
    }
};
