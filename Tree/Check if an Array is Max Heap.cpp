class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        int a = n/2;
        bool bl = false;
        for(int i = a-1;i>=0;i--){
            int x = (2*i)+1;
            int y = (2*i)+2;
            if(x < n){
                if(arr[i] < arr[x]){
                    return false;
                }
            }
            if(y < n){
                if(arr[i] < arr[y]){
                    return false;
                }
            }
        }
        return true;
    }
};
