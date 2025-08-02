
// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
         int c=0,ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++) {
            if(arr[i]<=k) c--;
            else c++;
            if(c<=0 and !m.count(c)) m[c]=i;
            if(c<=0 and m.count(c-1))ans=max(ans,i-m[c-1]);
            if(c>0) ans=i+1;
        }
        return ans;
        
    }
};
