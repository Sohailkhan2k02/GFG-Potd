//T.C : O(nlogk)
//S.C : O(k)
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        int n=arr.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>v;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                v.push_back(pq.top());
                pq.pop();
            }
        }
    
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        for(int i=0; i<n; i++){
            arr[i]=v[i];
        }
    }
};
