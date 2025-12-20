class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int pos=0;
        for(int i=0;i<n;i++){
            if(arr[i]==k){
                return i;
            }
        }
    for(int i=0;i<n;i++){
        if(arr[i]<k){
            pos++;
        }
    }
    return pos;
    }
};
