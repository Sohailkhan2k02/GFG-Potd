class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        
        int x=start;
        
        for(int i=0; i<n; i++){
            if(x<arr[i]) return false;
            else if(x==arr[i]){
                if(x==end) return true;
                else x++;
            }
        }
        
        return false;
    }
};
