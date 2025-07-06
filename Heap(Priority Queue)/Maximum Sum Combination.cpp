class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n=a.size(), m=b.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                int sum=a[i]+b[j];
                if(pq.size()==k && sum<pq.top()) break;
                pq.push(a[i]+b[j]);
                if(pq.size()>k) pq.pop();
            }
        }
        
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
