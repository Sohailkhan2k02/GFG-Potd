//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
    int res=-1;
    int findMaxForN(Node* root, int n) {
        // code here
        if(!root){
            return 0;
        }
        if(root->key<=n){
            res=max(res,root->key);
        }
        findMaxForN(root->left,n);
        findMaxForN(root->right,n);
        return res;
        
    }
};
