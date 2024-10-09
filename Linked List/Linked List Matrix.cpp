//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        int n=mat.size(),m=mat[0].size();
        vector<vector<Node*>>res(n,vector<Node*>(m,NULL));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                res[i][j]=new Node(mat[i][j]);
                if(i<n-1) res[i][j]->down=res[i+1][j];
                if(j<m-1) res[i][j]->right=res[i][j+1];
            }
        }
        return res[0][0];
    }
};
