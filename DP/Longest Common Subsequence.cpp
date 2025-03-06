//T.C : O(n*m)
//S.C : O(m)
class Solution {
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.size(),m=s2.size();
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=0; i<=n; i++){
           for(int j=0;j<=m;j++){
               if(i==0 || j==0){
                   curr[j]=0;
               }else if(s1[i-1]==s2[j-1]){
                   curr[j]=1+prev[j-1];
               }else{
                   curr[j]=max(prev[j],curr[j-1]);
               }
               
           }
           prev = curr;
       }
       return prev[m];
    }
};
