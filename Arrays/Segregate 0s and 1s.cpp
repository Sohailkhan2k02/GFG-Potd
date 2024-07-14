//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int c1=0,c2=0;
        for(int i=0; i<n; i++){
            if(arr[i]==0) c1++;
            else c2++;
        }
        int k=0;
        while(c1--){
            arr[k++]=0;
        }
        while(c2--){
            arr[k++]=1;
        }
    }
};
