//T.C : O(logn)
//S.C : O(1)
class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int ind=lower_bound(arr,arr+n,k)-arr;
        if(ind == 0){
            return arr[ind];
        }
        else if(abs(arr[ind] - k) > abs(arr[ind - 1] - k)){
            return arr[ind - 1];
        }
        return arr[ind];
    } 
};
