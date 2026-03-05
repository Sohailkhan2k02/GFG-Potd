class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.length();
        int i=0, j=0, cnt=0, maxi=-1e9;
        int f[26]={0};

        for(; j<n; j++){
          if(f[s[j]-'a']==0){
            cnt++;
          }
          f[s[j]-'a']++;
          for(; i<n && cnt>k; i++){
            f[s[i]-'a']--;
            if(f[s[i]-'a']==0) cnt--;
          }
          if(cnt==k) maxi=max(maxi, j-i+1);
        }

        return maxi==-1e9?-1:maxi;      
    }
};
