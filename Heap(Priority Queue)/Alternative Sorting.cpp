//T.C : O(n*logn)
//S.C : O(n)
class Solution {
  public:
    vector<int> alternateSort(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        priority_queue<int>pq;
        priority_queue<int,vector<int>,greater<int>>qp;
        for(auto i:arr){
            pq.push(i);
            qp.push(i);
        }
        for(int i=0; i<n; i+=2){
            arr[i]=pq.top();pq.pop();
            arr[i+1]=qp.top();qp.pop();
        }
        return arr;
    }
};
