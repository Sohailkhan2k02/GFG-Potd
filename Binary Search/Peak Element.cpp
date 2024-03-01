//T.C : O(log(n))
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
        int l = 0;
        int r = n-1;
        
        while(l < r) {
            
            int mid = l + (r-l)/2;
            
            if(arr[mid] < arr[mid+1])
                l = mid+1;
            else
                r = mid;
            
        }
        
        return l;
    }
};
