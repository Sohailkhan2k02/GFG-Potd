//T.C : O(n)
//S.C : O(1)
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        int n=str.size();
        vector<int>tmp(26,0);
        for(int i=0; i<n; i++){
            tmp[str[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(tmp[i]>1){
                tmp[i]=1;
            }
        }
        
        string s="";
        for(int i=0; i<n; i++){
            if(tmp[str[i]-'a']){
                s+=str[i];
                tmp[str[i]-'a']--;
            }
        }
        return s;
    }
};
