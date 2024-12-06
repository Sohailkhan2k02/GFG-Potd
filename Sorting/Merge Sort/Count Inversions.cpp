//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    // Function to count inversions in the array.
    int merge(vector<int>&arr, int s, int e){
        int cnt=0;
        int m=s+(e-s)/2;
        vector<int>res;
        int i=s,j=m+1;
        while(i<=m && j<=e){
            if(arr[i]<=arr[j]){
                res.push_back(arr[i++]);
            }
            else{
                cnt+=m-i+1;
                res.push_back(arr[j++]);
            }
        }
        while(i<=m) res.push_back(arr[i++]);
        while(j<=e) res.push_back(arr[j++]);
        for(int i=0; i<res.size(); i++){
            arr[i+s]=res[i];
        }
        return cnt;
    }
    int mergeSort(vector<int>&arr, int s, int e){
        int cnt=0;
        if(s<e){
            int m=s+(e-s)/2;
            cnt+=mergeSort(arr,s,m);
            cnt+=mergeSort(arr,m+1,e);
            cnt+=merge(arr,s,e);
        }
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        return mergeSort(arr,0,n-1);
    }
};
