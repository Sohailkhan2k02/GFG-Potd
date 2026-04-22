class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int sum=0;
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            sum= sum+ arr[i];
            mp[i]= sum;
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int first=  queries[i][0];
            int second= queries[i][1];
            int num_q= (second-first)+1;
            int get_ans=0;
            if(first==0){
                 get_ans= mp[second] / num_q;
                
            }
            else{
                
                get_ans= (mp[second]- mp[first-1]) / num_q;
            }
            ans.push_back(get_ans);
        }
        return ans;
    }
};
