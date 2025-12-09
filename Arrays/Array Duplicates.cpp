class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        // code here
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        
        for(auto it: mpp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        
        if(ans.empty()){
            ans.push_back(-1);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};
