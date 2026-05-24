class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int left=0, right=arr.size()-1;
        while(right>left){
            if(arr[left]>arr[right]) left++;
            else right--;
        }
        return arr[left];
    }
};
