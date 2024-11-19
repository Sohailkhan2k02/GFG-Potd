//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n=arr.size();
        int ind=-1;
        for(int i=n-2; i>=0; i--){
            if(arr[i]<arr[i+1]) {ind=i; break;}
        }
        if(ind==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        for(int i=n-1; i>ind; i--){
            if(arr[i]>arr[ind]){
                swap(arr[i],arr[ind]);
                break;
            }
        }
        reverse(arr.begin()+ind+1,arr.end());
    }
};
