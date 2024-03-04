// T.C : O(n)
// S.C : O(1)
class Solution{
  public:
    void swapElements(int arr[], int n){
        
        // Your code here
        for(int i=0; i<n-2; i++){
            swap(arr[i],arr[i+2]);
        }
        
    }
};
