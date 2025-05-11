//T.C : O(nlogk)
//S.C : O(logk)
// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0 ;i<arr.size();i++){
            int sum = 0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                if(pq.empty() || pq.size()<k){
                    pq.push(sum);
                }
                else if(!pq.empty() && pq.size()>=k && pq.top()<sum){
                    pq.pop();
                    pq.push(sum);
                }
              
            }
        }
        return pq.top();
    }
};
