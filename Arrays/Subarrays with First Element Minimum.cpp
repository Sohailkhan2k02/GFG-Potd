class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int ans = 0;
        stack<int> st;
        for(int i = 0;i<arr.size();i++){
            while(!st.empty() and arr[st.top()]>arr[i]){
                ans += (i-st.top());
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            ans += (arr.size()-st.top());
            st.pop();
        }
        
        return ans;
    }
};
