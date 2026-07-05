class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int st[26];
      int ed[26];
      
      memset(st, -1, sizeof(st));
      memset(ed, -1, sizeof(ed));
      
      int n=s.size();
      for(int i=0; i<n; i++){
        char ch=s[i];
        if(st[(ch-97)] == -1) st[(ch-97)]=i;  
      }     
      
      for(int i=n-1; i>=0; i--){
        char ch=s[i];  
        if(ed[(ch-97)] == -1) ed[(ch-97)]=i;  
      }
      
      
      
      int ans=-1;
      for(int i=0; i<n; i++){
        char ch=s[i];  
        ans=max(ans, ed[(ch-97)]-st[(ch-97)]-1);  
      }
      
      return ans;
    }
};
