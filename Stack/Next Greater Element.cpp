//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>vec(n,-1);
        stack<long long>st;
        st.push(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            
            if(st.size()!=0)
            vec[i]=st.top();
                
            st.push(arr[i]);
                
        }
        return vec;
    }
};
