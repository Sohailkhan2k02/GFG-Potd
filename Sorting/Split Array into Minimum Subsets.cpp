class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        vector<vector<int>> vec;
        sort(arr.begin(), arr.end());
        int last = arr[0];
        vector<int> v;
        v.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if(arr[i] == last + 1){
                v.push_back(arr[i]);
            }else{
                vec.push_back(v);
                v.clear();
                v.push_back(arr[i]);
            }
            last = arr[i];
        }
        vec.push_back(v);
        return vec.size();
    }
};
