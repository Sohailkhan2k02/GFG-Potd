class Solution {
  public:
    bool canSplit(vector<int>& arr, int k, int mid){
        int subarray=0, currsum=0;
        for(int n:arr){
            currsum+=n;
            if(currsum>mid){
                currsum=n;
                subarray+=1;
            }
        }
        return subarray+1<=k;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int l=*max_element(arr.begin(), arr.end());
        int r=accumulate(arr.begin(), arr.end(), 0);
        int result=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canSplit(arr, k, mid)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};
