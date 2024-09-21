//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        int n=str.size();
        vector<int>lps(n,0);
        int i=1,len=0;
        while(i<n){
            if(str[i]==str[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else if(str[i]!=str[len]){
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps[n-1];
    }
};
