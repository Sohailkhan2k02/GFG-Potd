//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
         int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                arr[i]=2*arr[i];
                arr[i+1]=0;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                arr[cnt++]=arr[i];
            }
        }
        while(cnt<n){
            arr[cnt++]=0;
        }
        return arr;
    }
};
