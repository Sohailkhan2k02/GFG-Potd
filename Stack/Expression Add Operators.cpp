class Solution {
  public:
    void fun(string &s, long long t, int pos, long long val, long long last, string expr, vector<string> &ans){
        if(pos == s.size()){
            if(val == t)
              ans.push_back(expr);
            return;  
        }
        
        for(int i=pos;i<(int)(s.size());i++){
            string numStr = s.substr(pos, i-pos+1);
            if(numStr.size()>1 && numStr[0]=='0')
              break;
              
            long long num = stoll(numStr);
            
            if(pos==0)
              fun(s, t, i+1, num, num, numStr, ans);
            else{
                fun(s, t, i+1, val+num, num, expr + "+" + numStr, ans);
                fun(s, t, i+1, val-num, -num, expr + "-" + numStr, ans);
                fun(s, t, i+1, val-last+last*num, last*num, expr + "*" + numStr, ans);
                
            }  
        }
        return;
        
    }
  
    vector<string> findExpr(string &s, int target) {
        // code here
        vector<string> ans;
        string expr;
        fun(s, target, 0, 0, 0, expr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
