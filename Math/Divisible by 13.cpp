class Solution {
  public:
    bool divby13(string &s) {
        // code here
        string str="";
        int n=s.length();
        for(int i=0;i<n;i++){
            str+=s[i];
            if(stoi(str)/13<1){
                continue;
            }
            int rem=stoi(str)%13;
            if(rem==0){
                str="";
            }
            else{
                str=to_string(rem);
            }
        }
        return str==""?true:false;
    }
};
