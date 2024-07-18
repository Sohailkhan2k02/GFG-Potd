//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        int n=arr.size();
        if(n==1) return 1;
        int inc=1,dec=1;
        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]) inc=dec+1;
            else if(arr[i]<arr[i-1]) dec=inc+1;
        }
        return max(inc,dec);
    }
};
