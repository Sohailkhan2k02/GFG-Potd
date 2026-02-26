class Solution {
  public:
    bool areIsomorphic(string &str1, string &str2) {
        // code here
        unordered_map<char,char>mpp1,mpp2;
        int n=str1.size(),m=str2.size();
        if(n!=m) return false;
        
        for(int i=0; i<n; i++){
            mpp1[str1[i]]=str2[i];
            mpp2[str2[i]]=str1[i];
        }
        
        for(int i=0; i<n; i++){
            if(mpp1[str1[i]]!=str2[i] || mpp2[str2[i]]!=str1[i]) return false;
        }
        
        return true;
    }
};
