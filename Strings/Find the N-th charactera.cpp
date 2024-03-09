// T.C: O(r*n)
// S.C: O(n)

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        while(r--){
            string temp;
            for(int i=0; i<=n; i++){
                if(s[i]=='1'){
                    temp+="10";
                }
                else{
                temp+="01";
                }
            }
            s=temp;
        }
        return s[n];
    }
};
