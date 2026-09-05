
class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        unordered_map<int,int>mpp;
        int len=1;
        for(auto i:a){
            mpp[i]=max({mpp[i],mpp[i-1]+1,mpp[i+1]+1});
            len=max(len,mpp[i]);
        }
        return len;
    }
};
