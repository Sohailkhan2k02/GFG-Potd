// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        // int n=mat.size(),m=mat[0].size();
        // set<int>st;
        //  for(int i=0; i<n; i++){
        //      for(int j=0; j<m; j++){
        //          if(mat[i][j]==1){
        //              st.insert(i);
        //              break;
        //          }
        //      }
        //  }
        //  if(st.size()==n) return -1;
        //  for(int i=0; i<n; i++){
        //      if(st.find(i)==st.end()) return i;
        //  }
        //  return -1;
        int n = mat.size();
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (mat[cnt][i] == 1) {
                cnt = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != cnt && (mat[cnt][i] == 1 || mat[i][cnt] == 0)) {
                return -1;
            }
        }
    
        return cnt;
    }
};
