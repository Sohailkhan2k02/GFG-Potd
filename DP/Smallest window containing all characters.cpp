class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        vector<int> freqs(26,0);
        vector<int> freqp(26,0);
        int unique=0;
        for(auto it:p){
            if(freqp[it-'a']==0)unique++;
            freqp[it-'a']++;
        }
        int start=0,end=0,minlen=INT_MAX,match=0;
        string ans="";
        while(end<s.size()){
            freqs[s[end]-'a']++;
            if(freqs[s[end]-'a']==freqp[s[end]-'a'] 
                && freqp[s[end]-'a'] >0 )match++;
            if(match>=unique){
                while(start<=end && 
                      freqs[s[start]-'a']>freqp[s[start]-'a']){
                      freqs[s[start]-'a']--;   
                      start++;
                }
                int len=end-start+1;
                if(len<minlen){
                    minlen=len;
                    ans=s.substr(start,len);
                }
            }
            end++;
        }
        return ans;
    }
};
