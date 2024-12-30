//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int> mp;
        for(auto & i : a){
           mp[i]++;
        }
        for(auto & i : b){
            mp[i]++;
        }
        return mp.size();
    }
};
