class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        int ind=-1;
        for(int i=1;i<s.size();i++){
            if(ind!=-1 && s[ind]>s[i]) continue;
            if(s[i]>s[i-1]){
                ind=i;
            }
            if(s[i]==s[ind] && ind!=-1) ind=i;
            
        }
        if(ind==-1) return s;
        
        for(int i=0;i<s.size();i++){
            if(s[i]<s[ind]) {
                swap(s[i],s[ind]);
                
                break;
            }
            
        }
        return s;
    }
};
