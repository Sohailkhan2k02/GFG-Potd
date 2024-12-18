//T.C : O(nlogn)
//S.C : O(1)
class Solution {
  public:
    bool f(int mid, vector<int>&arr, int k,int n){
        int cnt=1,sum=0;
        for(int i=0; i<n; i++){
            if(arr[i]>mid) return false;
            if(sum+arr[i]>mid){
                cnt++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        return cnt<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        int l=*max_element(arr.begin(),arr.end()),h=accumulate(arr.begin(),arr.end(),0);
        int res=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(f(m,arr,k,n)){
                res=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return res;
    }
};
