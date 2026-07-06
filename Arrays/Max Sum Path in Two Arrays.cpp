class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int arr1Sum=0,arr2Sum=0,i=0,j=0;
        int n=a.size(),m=b.size();
        while(i<n&& j<m){
            if(a[i]==b[j]){
              int temp=arr1Sum;
              arr1Sum=max(arr1Sum+a[i],arr2Sum+b[j]);
              arr2Sum=max(temp+a[i],arr2Sum+b[j]);
              i++;
              j++;
            } else if(a[i]<b[j]){
              arr1Sum+=a[i];
              i++;
            } else if(a[i]>b[j]){
              arr2Sum+=b[j];
              j++;
            }
        }
        while(i<n){
            arr1Sum+=a[i];
            i++;
        }
        while(j<m){
            arr2Sum+=b[j];
            j++;
        }
        return max(arr1Sum,arr2Sum);
    }
};
