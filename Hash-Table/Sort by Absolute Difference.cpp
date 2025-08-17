class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        multimap<int,int>m;
        for(auto i:arr)
        {
            m.insert({abs(i-x),i});
        }
        int i=0;
        for(auto &j:m){
            arr[i++]=j.second;
        }
    }
};
