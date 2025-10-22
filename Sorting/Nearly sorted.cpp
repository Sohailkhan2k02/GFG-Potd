class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<=k;i++){
           pq.push(arr[i]);
        }
        
        int j=k+1;
        
        for(int i=0;i<n;i++){
           int j=min(i+k+1,n-1);
           arr[i]=pq.top();
           pq.pop();
           if(i+k+1<n)
           pq.push(arr[j]);
        }
    }
};
