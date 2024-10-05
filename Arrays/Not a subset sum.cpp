//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
        using ll=long long;
        ll res=1;
        for(auto i:arr){
            if(i>res) return res;
            res+=i;
        }
        return res;
    }
};
