//T.C : O(n*m)
//S.C : O(m)
// User function Template for C++

class Solution {
  public:
  int lcs(int n, int m, string s1, string s2)
    {
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1; i<=n; i++){
           for(int j=1;j<=m;j++){
               if(s1[i-1]==s2[j-1]){
                   curr[j]=1+prev[j-1];
               }else{
                   curr[j]=max(prev[j],curr[j-1]);
               }
               
           }
           prev = curr;
       }
       return prev[m];
    }
    int longestPalinSubseq(string &A) {
        // code here
        string t= A;
        int n = A.size();
        int m = A.size();
        reverse(t.begin(), t.end());
        return lcs(n, m, A, t);
    }
};
