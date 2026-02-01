class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        pair<int, int> mx = {INT_MIN, 0};
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(i>k-1 && mx.second <= i-k){
                mx = {INT_MIN, 0};
                for(int j=i-k+1;j<i;j++){
                    mx = max(mx, {arr[j], j});
                }
            }
            mx = max(mx, {arr[i], i});
            if(i>=k-1)
                ans.push_back(mx.first);
        }
        return ans;
    }
};
