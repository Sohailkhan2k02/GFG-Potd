class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        int m = b.size();
        int n = a.size();
        vector<int>ans;
        vector<int>lps(m,0);
        lps[0]=0;
        
        int first = 0;
        int second = 1;
        
        // finding LPS
        while(second<m){
            
            if(b[first]==b[second]){
                lps[second] = first+1;
                first++;
                second++;
            }
            else if(first==0){
                lps[second]=0;
                second++;
            }
            else first = lps[first-1];
            
            
        }
        // string matching;
        b.push_back(-1);
        lps.push_back(0);
        first = 0;
        second = 0;
        
        while(second<n){
            
            if(b[first]==a[second]){
                first++;
                second++;
            }
            else if(first==0)second++;
            else{
                
                if(first==m)ans.push_back(second-m);
                first = lps[first-1];
            }
            
        }
        
        if(second==n && first==m)ans.push_back(second-m);
        return ans;
        
        
    }
};
