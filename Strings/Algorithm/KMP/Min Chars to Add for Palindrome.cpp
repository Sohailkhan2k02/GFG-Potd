//T.C : O(n+n)
//S.C : O(n+n)
class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        int n=s.size();
        string temp=s;
        reverse(temp.begin(),temp.end());
        s+="$";
        s+=temp;
        int pre=0,suff=1;
        vector<int>lps(s.size(),0);
        while(suff<s.size()){
            if(s[suff]==s[pre]){
                lps[suff]=pre+1;
                suff++,pre++;
            }
            else{
                if(pre==0){
                    suff++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
        return n-lps[s.size()-1];
    }
};
