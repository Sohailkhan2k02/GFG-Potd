class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n = (int)arr.size();
        
        arr[0] = arr[0] ^ arr[1];
        int s = 0 ;
        s = s ^ arr[0];
        for(int i = 1;(i+1)<n;i++)
        {
            arr[i] = (arr[i] ^ s ^ arr[i+1]);
            s^=arr[i];
        }
        
        arr[n-1] = s ;
        
    }
};
