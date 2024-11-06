//T.C : O(n)
//S.C : O(1)
class Solution {
  public:
  int sum=0;
  void f(Node* root,int dig){
      if(root==NULL) return;
      dig=dig*10+root->data;
      if(root->left==NULL && root->right==NULL){
          sum+=dig;
          return;
      }
      
      f(root->left,dig);
      
      f(root->right,dig);
  }
    int treePathsSum(Node *root) {
        // code here.
        int dig=0;
        f(root,dig);
        return sum;
    }
};
