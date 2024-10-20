//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        int n=arr.size();
        int v=0;
        for(int i=1; i<n; i++){
            v^=arr[i];
        }
        if(v==arr[0]) return n;
        return 0;
    }
};
