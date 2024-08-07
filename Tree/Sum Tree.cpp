//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
   int f(Node* root){
       if(root==NULL) return 0;
       
       return root->data+f(root->left)+f(root->right);
   }
    bool isSumTree(Node* root) {
        // Your code here
        if(root==NULL || root->left==NULL && root->right==NULL) return true;
        int lsum=f(root->left);
        int rsum=f(root->right);
        return (root->data==lsum+rsum) && isSumTree(root->left) && isSumTree(root->right);
        
    }
};
