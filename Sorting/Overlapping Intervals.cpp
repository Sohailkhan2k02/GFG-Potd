class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        vector<int>temp=arr[0];
        for(int i=1;i<n;i++){
            int start=arr[i][0],end=arr[i][1];
            if(temp[0]<=start && start<=temp[1]){
                temp={min(start,temp[0]),max(end,temp[1])};
            } else {
                ans.push_back(temp);
                temp={arr[i][0],arr[i][1]};
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
