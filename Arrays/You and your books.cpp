//T.C : O(n)
//S.C : O(1)
#define ll long long
class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        ll maxi=0,sum=0;
        for(int i=0; i<n; i++){
            if(arr[i]<=k){
                sum+=arr[i];
            }
            else{
                sum=0;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};
