//T.C : O(n)
//S.C : O(n)
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int> &arr,int k) {
        // your code here
        int n=arr.size();
        vector<int> ans;
        deque<int> q;
        int i=0,j=0;
        while(j<n){
            while(!q.empty() && q.back()<arr[j])
            q.pop_back();
           q.push_back(arr[j]);
           if(j-i+1<k)
           j++;
           else if(j-i+1==k){
               ans.push_back(q.front());
               if(arr[i]==q.front())
               q.pop_front();
               i++;
               j++;
           }
        }
       return ans; 
    }
};
