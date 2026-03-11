class Solution {
  public:
    vector<int>nextSmaller(vector<int>&arr){
      
      int n=arr.size();
      vector<int>res(n);
      stack<int>st;
      for(int i=n-1;i>=0;i--){
          while(!st.empty() && arr[st.top()]>=arr[i]){
              st.pop();
          }
          if(!st.empty()) res[i]=st.top();
          else res[i]=n;
          st.push(i);
      }
      return res;
  }
  
  vector<int>prevSmaller(vector<int>&arr){
      
      int n=arr.size();
      vector<int>res(n);
      stack<int>st;
      for(int i=0;i<n;i++){
          while(!st.empty() && arr[st.top()]>arr[i]){
              st.pop();
          }
          if(!st.empty()) res[i]=st.top();
          else res[i]=-1;
          st.push(i);
      }
      return res;
  }
    int sumSubMins(vector<int> &arr) {
        // code here
        vector<int>nex=nextSmaller(arr);
        vector<int>pre=prevSmaller(arr);
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            
            ans+=(arr[i])*((i-pre[i])*(nex[i]-i));
        }
        return ans;
    }

};
