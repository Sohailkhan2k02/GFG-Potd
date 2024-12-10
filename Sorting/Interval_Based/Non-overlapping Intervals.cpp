//T.C : O(n*logn)
//S.C : O(1)
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });
        
       int prev=intervals[0][1];
        
       int  ans=0;
        for(int i=1;i<n;i++){
            if(prev>intervals[i][0]){
                ans++;
            }
            else{
                prev=intervals[i][1];
            }
        }
        return ans;
    }
};
