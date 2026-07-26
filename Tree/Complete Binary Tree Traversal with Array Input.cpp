class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        queue<pair<int,int>>q1;
      vector<vector<int>>ans;
      if(arr.size()==1){
         ans.push_back({arr[0]});
         return ans;
      }
      q1.push({arr[0],0});
      int i=0;
        while(!q1.empty()){
            int size=q1.size();
            priority_queue<int,vector<int>,greater<int>>pq;
            for(int j=0;j<size;j++){
              int first=q1.front().first;
              int idx=q1.front().second;
              q1.pop();
              pq.push(first);
             int idx1=2*idx+1;
             if(idx1<arr.size()) q1.push({arr[idx1],idx1});
             int idx2=2*idx+2;
             if(idx2<arr.size()) q1.push({arr[idx2],idx2});
              
            }
            vector<int>v;
            while(!pq.empty()){
            v.push_back(pq.top());
               pq.pop();
            }
            ans.push_back(v);
            i++;
        }
        return ans;
    }
};
