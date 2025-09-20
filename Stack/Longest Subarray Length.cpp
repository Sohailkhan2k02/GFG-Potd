class Solution {
  public:
void ngiFun(vector<int> &ngi, vector<int> &arr, int &n){
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while((!st.empty()) && (arr[st.top()]<=arr[i]))
              st.pop();
            if(!st.empty())
              ngi[i] = st.top();
            st.push(i);  
        }
        return;
    }
    
    void pgiFun(vector<int> &pgi, vector<int> &arr, int &n){
        stack<int> st;
        for(int i=0;i<n;i++){
            while((!st.empty()) && (arr[st.top()]<=arr[i]))
              st.pop();
            if(!st.empty())
              pgi[i] = st.top();
            st.push(i);  
        }
        return;
    }
  
    int longestSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ngi(n, n), pgi(n, -1);
        
        ngiFun(ngi, arr, n);
        pgiFun(pgi, arr, n);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int len = ngi[i] - pgi[i] - 1;
            if(len >= arr[i])
              ans = max(ans, len);
        }
        return ans;
    }
};
