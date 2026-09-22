class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        int n = s.size() ;
        vector<vector<int>> indices(26) ;
        
        for(int i=0 ; i<n ; i++){
            int idx = s[i] - 'a' ;
            
            indices[idx].push_back(i) ;
        }
        
        string res = "" ;
        
        for(auto &str : d){
            bool found = true ;
            int currIdx = -1 ;
            
            for(int i=0 ; i<str.size() ; i++){
                int idx = str[i] - 'a' ;
                if(indices[idx].empty()){
                    found = false ;
                    break ;
                }
                
                auto it = upper_bound(indices[idx].begin() , indices[idx].end() , currIdx) ;
                if(it == indices[idx].end()){
                    found = false ;
                    break ;
                }
                
                currIdx = *it ;
            }
            
            if(found){
                if(res.empty() || str.size() > res.size()){
                    res = str ;
                }else if(res.size() == str.size()){
                    if(str < res){
                        res= str ;
                    }
                }
            }
            
            
        }
        
        return res ;
    }
};
