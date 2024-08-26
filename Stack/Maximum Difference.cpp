//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int>st;
        st.push(arr[0]);
        vector<int>l(n,0);
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[i]<=st.top()){
                st.pop();
            }
            if(!st.empty()){
                l[i]=st.top();
            }
            st.push(arr[i]);
        }
        // for(auto i:l) cout<<i<<" ";
        // cout<<"\n";
        vector<int>r(n,0);
        for(int i=n-2; i>=0; i--){
            while(!st.empty() && arr[i]<=st.top()){
                st.pop();
            }
            if(!st.empty()){
                r[i]=st.top();
            }
            st.push(arr[i]);
        }
        // for(auto i:r) cout<<i<<" ";
        // cout<<"\n";
        int diff=-1;
        for(int i=0; i<n; i++){
            diff=max(abs(l[i]-r[i]),diff);
        }
        return diff;
    }
};
