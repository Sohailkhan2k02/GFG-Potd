class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int,int>>st;
        st.push({color[0],radius[0]});
        int n = color.size() , i = 1 ,ans = 0;
        while(i<n){
            while(!st.empty() && i<n && st.top().first == color[i] && st.top().second == radius[i]){
                st.pop();
                i++;
            }
            if(i<n)st.push({color[i],radius[i]});
            i++;
        }
        while(!st.empty()){
            st.pop();
            ans++;
        }
        return ans;
        
    }
};
