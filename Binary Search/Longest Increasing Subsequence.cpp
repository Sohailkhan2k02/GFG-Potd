//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    int lis(vector<int>& a) {
        // code here
        int n=a.size();
        vector<int>ans;
       for(int i=0; i<n; i++){
           auto it=lower_bound(begin(ans), end(ans), a[i]);
           if(it==end(ans)){
               ans.push_back(a[i]);
           }
           else{
               *it=a[i];
           }
       }
       return ans.size();
    }
};
