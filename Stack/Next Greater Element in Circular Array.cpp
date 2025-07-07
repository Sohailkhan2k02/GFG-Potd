// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
       vector<long long>v(n,-1);
       stack<long long>st;
       st.push(arr[n-1]);
       for(int i=n-2;i>=0;i--)
       {
           while(!st.empty() && st.top()<=arr[i])
           {
               st.pop();
           }
           
           if(st.size()!=0)
           v[i]=st.top();
           
           st.push(arr[i]);
       }
       
       return v;
       
    }
};
