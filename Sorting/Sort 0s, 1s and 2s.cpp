//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i=0,j=0,k=n-1;
        while(j<=k){
            if(arr[j]==0){
                swap(arr[i++],arr[j++]);
            }
            else if(arr[j]==2){
                swap(arr[j],arr[k--]);
            }
            else j++;
        }
    }
};
