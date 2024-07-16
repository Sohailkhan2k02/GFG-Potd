//T.C : O(n)
//S.C :O(n)
class Solution {
  public:
    string printString(string s, char ch, int cnt) {
        // Your code goes here
        int n=s.size(),ind=-1;
        string res="";
        for(int i=0; i<n; i++){
            if(s[i]==ch){
                cnt--;
            }
            if(cnt==0){
                ind=i;
                break;
            }
        }
        for(int i=ind+1; i<n; i++){
            res+=s[i];
        }
        if(ind==-1){
            return "";
        }
        return res;
    }
};
