class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        int n = arr1.size();
        int m = arr2.size();
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>> > pq; 
        
        for(int i=0;i<n && i<k;i++){
            pq.push({arr1[i]+arr2[0],{i,0}});
        }
        
        vector<vector<int>> ans;
        while(!pq.empty() && k--){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            ans.push_back({arr1[i],arr2[j]});
            if(j+1<m){
                pq.push({arr1[i]+arr2[j+1],{i,j+1}});
            }
        }
        
        return ans;
    }
};
