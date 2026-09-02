class Solution {
  public:
    int solve(int n, string s) {
        // code here
        vector<int> check(26 , false) ;
        int res = 0 ;
        int cnt = n ;
        
        for(int i=0 ; i<s.size() ; i++){
            int idx = s[i] - 'A' ;
            if(check[idx] == 1){
                check[idx] = 0;
                cnt++;
            }else if(check[idx] == 0){
                if(cnt > 0){
                    cnt--;
                    check[idx] = 1 ;
                }else{
                    res++; 
                    check[idx] = -1 ;
                }
            }
        }
        
        return res ;
    }
};
