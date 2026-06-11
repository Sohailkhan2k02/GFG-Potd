class Solution {
  public:
    int findIndex(string &s) {
        // code here
        int n=s.length();
        int cl=0;
        for(int i=0; i<n; i++){
            if(s[i]==')') cl++;
        }

        int op=0;
        for(int i=0; i<n; i++){
            if(op==cl) return i;
            if(s[i]=='('){
                op++;
            }else cl--;
        }
        if(op==cl) return n;
        return -1;        
    }
};
