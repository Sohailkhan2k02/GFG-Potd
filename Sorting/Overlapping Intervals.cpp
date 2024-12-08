//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>vc;
        vc.push_back({arr[0][0],arr[0][1]});
        for(int i=1; i<n; i++){
            if(arr[i][0]<=vc.back()[1]){
                vc.back()[1]=max(vc.back()[1],arr[i][1]);
            }
            else{
                vc.push_back({arr[i][0],arr[i][1]});
            }
        }
        return vc;
    }
};
