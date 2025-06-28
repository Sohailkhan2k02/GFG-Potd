//T.C : O(nlogn)
//S.C : O(n)
class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        vector<int> ans;
        for(int i = 0; i < a.size(); i++){
            int ele = a[i];
            int idx = upper_bound(b.begin(), b.end(), ele) - b.begin();
            ans.push_back(idx);
        }
        return ans;
    }
};
