//T.C : O(n)
//S.C : O(1)
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        int cnt=0;
        vector<bool>tmp(26,0);
        for(auto i:str){
            if(i!=' '){
                tmp[i-'a']=true;
                cnt++;
            }
        }
        if(cnt<26) return false;
        int u=0;
        for(auto i:tmp){
            if(i) u++;
        }
        int r=26-u;
        return r<=k;
    }
};
