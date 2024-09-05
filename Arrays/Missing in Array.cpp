//T.C : O(n)
//S.C : O(1)
class Solution{
  public:
    int missingNumber(int n,vector<int>& arr){
        int xr1=0,xr2=0;
        for(int i=0;i<n-1; i++){
            xr1^=arr[i];
        }
        for(int i=1; i<=n; i++){
            xr2^=i;
        }
        return xr1^xr2;
    }
};
