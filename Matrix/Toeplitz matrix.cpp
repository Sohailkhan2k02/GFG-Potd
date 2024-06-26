//T.C : O(n*m)
//S.C : O(1)
bool isToeplitz(vector<vector<int>>& mat) {
    // code here
     int n = mat.size();
    int m = mat[0].size();
    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j] != mat[i-1][j-1])
            return 0;
        }
    }
    return 1;
}
