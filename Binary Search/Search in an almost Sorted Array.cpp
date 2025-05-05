//T.C : O(nlogn)
//S.C : O(1)
// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
         int n=arr.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(arr[mid]==target) return mid;
            if(arr[mid]<=target)
            {
                if(arr[mid-1]==target) return mid-1;
                low=mid+1;
            }
            else
            {
                if(arr[mid+1]==target) return mid+1;
                high=mid-1;
            }
        }
        return -1;
    }
};
