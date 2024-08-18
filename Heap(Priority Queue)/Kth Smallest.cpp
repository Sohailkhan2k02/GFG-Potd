//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        for(auto i:arr){
            pq.push(i);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
