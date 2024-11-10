//T.C: O((n+m)log(n+m))
//S.C: O(n+m)
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        set<int>st;
        for(auto i:a) st.insert(i);
        for(auto i:b) st.insert(i);
        vector<int>res(st.begin(),st.end());
        return res;
    }
};
