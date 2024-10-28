//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        // code here
        set<int>st;
        vector<int>res;
        for(auto i:arr){
            if(st.find(i)==st.end()){
                st.insert(i);
                res.push_back(i);
            }
        }
        return res;
    }
};
