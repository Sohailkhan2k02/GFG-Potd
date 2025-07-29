class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        int n=s.size();
        vector<int>firstOcc(26,-1),lastOcc(26,-1);
        
        for(int i=0;i<n;i++){
            if(firstOcc[s[i]-'a']==-1){
                firstOcc[s[i]-'a']=i;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(lastOcc[s[i]-'a']==-1){
                lastOcc[s[i]-'a']=i;
            }
        }
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=int(s[i]);
            
            if(firstOcc[s[i]-'a']==i){
                firstOcc[s[i]-'a']=(-1*sum);
            } else if(lastOcc[s[i]-'a']==i){
                lastOcc[s[i]-'a']=(sum-int(s[i]));
            }
        }
        
        vector<int>ans;
        for(int i=0;i<26;i++){
            int val=lastOcc[i]+firstOcc[i];
            if(val>0) ans.push_back(val);
        }
        
        return ans;
    }
};
