class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        int count=0;
        int prefix_ind=0;
        int suffix_ind =1;
        int pos=1;
        int len=s.length();
        while(len>suffix_ind){
            if(s[prefix_ind]==s[suffix_ind]){
                prefix_ind++;
                count++;
                  suffix_ind++;
            }else{
                prefix_ind=0;
                count=0;
                pos++;
                suffix_ind=pos;
            }
        }
        return count;
    }
};
