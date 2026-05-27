class Solution {
  public:
    bool wifiRange(string &s, int x) {
        // code here
        int n=s.size();
        int last=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                
                if(last==-1){
                    if(i>x) return false;
                }
                else{
                    if((i-last-1) > 2*x) return false;
                }
                last=i;
            }
            
        }
        
        if(last==-1) return false;
        if(n-1-last >x) return false;
        
        return true;
    }
};
