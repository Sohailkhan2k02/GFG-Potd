class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int idx=lower_bound(arr.begin(),arr.end(),arr[i]+k)
            -arr.begin();
idx--;
            ans+=max(0,idx-i);
        }
        return ans;
    }
};
