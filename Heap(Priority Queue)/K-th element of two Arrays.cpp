//T.C : O(n*logn)
//S.C : O(n+m)
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        vector<int>v(arr1.begin(),arr1.end());
        v.insert(v.end(),arr2.begin(),arr2.end());
        priority_queue<int>pq;
        for(int i=0; i<v.size(); i++){
            pq.push(v[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
