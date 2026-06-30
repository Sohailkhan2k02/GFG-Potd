class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> P;
        for(int x : a) if(binary_search(b.begin(),b.end(),x)) P.push_back(x);
        
        vector<int> lis;
        for(int x : P){
            auto it = lower_bound(lis.begin(),lis.end(),x);
            if(it == lis.end()) lis.push_back(x);
            else *it = x;
        }
        
        return (a.size() - b.size()) + 2 * (b.size() - lis.size());
    }
};
