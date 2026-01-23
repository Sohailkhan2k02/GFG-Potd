class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n = arr.size();
    vector<int> leftCount(n, 0), rightCount(n, 0);

    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        leftCount[i] = st.empty() ? i : i - st.top() - 1;
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        rightCount[i] = st.empty() ? (n - 1 - i) : (st.top() - i - 1);
        st.push(i);
    }

    int mx = 0;
    for(int i = 0; i < n; i++){
        int total = leftCount[i] + rightCount[i] + 1;
        mx = max(mx, total);
    }
    return mx;
        
    }
};
