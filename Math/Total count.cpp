//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        // code here
        int cnt=0;
        int n=arr.size();
        for(int i=0; i<n; i++){
            cnt+=(arr[i]-1+k)/k;
        }
        return cnt;
    }
};
