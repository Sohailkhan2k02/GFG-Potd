//T.C : O(nlogk)
//S.C : O(logk)
class Solution{
public:
vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        vector<int> ans;
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i<arr.size();i++)
        {
            pq.push(arr[i]);
            if(pq.size()>k)
            pq.pop();
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;   
        
}
};
