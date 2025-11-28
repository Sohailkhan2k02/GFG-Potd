class Solution {
  public:
    vector<int> subsetXOR(int n) {
        // code here
        vector<int> ans;
        if(n==1) 
        {
         ans.push_back(n);  
        return ans; 
        }
        for(int i=1;i<=n;i++)
        {
            ans.push_back(i) ;
        }
        if(n%4 == 1) ans.erase(ans.begin() + n - 2); 
        if(n%4 == 2) ans.erase(ans.begin());        
        if(n%4 == 3) ans.erase(ans.begin() + n - 1);        

        return ans ;
    }
};
