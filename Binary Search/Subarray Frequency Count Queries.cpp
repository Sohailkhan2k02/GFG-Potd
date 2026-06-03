class Solution {
  public:
    int bs(vector<int>&a , int k){
      int st = 0 ,en = a.size()-1;
      while(st<=en){
          int mid = (st + en)/2;
          if(a[mid] == k)return mid+1;
          if(a[mid] <k)st = mid+1;
          else en = mid-1;
      }
      return st;
  }
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
       unordered_map< int, vector<int>>adj;
        for(int i = 0 ;i< arr.size() ; i++){
            adj[arr[i]].push_back(i);
        }
        vector<int>ans;
        
        for(auto &i: queries){
            if(adj.find(i[2]) == adj.end()){
                ans.push_back(0);
                continue;
            }
            int count = bs(adj[i[2]] , i[1]);
            // cout<<count<<endl;
            count-=bs(adj[i[2]] , i[0]-1);
            ans.push_back(count);
        }
        return ans;
    }
};
