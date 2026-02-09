class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int start =0;
        int end = arr.size()-1;
        int ans = 0;
        int n = arr.size();
        
        while(start<=end){
            
            int mid = start+((end-start)/2);
            
            if(arr[mid]==1){
                ans = mid;
                break;
            }
            else if(arr[mid]>arr[n-1]){
                start = mid+1;
            }
            else{
                ans=mid;
                end=mid-1;
            }
        }
        
        return ans;
    }
};
