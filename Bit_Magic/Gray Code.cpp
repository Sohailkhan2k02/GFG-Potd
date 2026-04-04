class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        vector<string> ans;
        
        int total = 1 << n;
        
        for(int i = 0; i < total; i++){
            int g = i ^ (i >> 1);
            
            string s = "";
            
            for(int j = n - 1; j >= 0; j--){
                if(g & (1 << j)) s += '1';
                else s += '0';
            }
            
            ans.push_back(s);
        }
        
        return ans;
    }
};
