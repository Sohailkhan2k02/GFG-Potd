//T.C: O(n)
//S.C: O(h)
class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {
        // code here
        if(root==NULL) return root;
        
        root->left=RemoveHalfNodes(root->left);
        root->right=RemoveHalfNodes(root->right);
        
        if(root->left==NULL && root->right!=NULL){
            return root->right;
        }
        
        else if(root->right==NULL && root->left!=NULL){
            return root->left;
        }
        
        return root;
    }
};
