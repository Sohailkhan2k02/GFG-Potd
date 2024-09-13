//T.C : O(n)
//S.C : O(recursive call stack)
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void dfs(Node* root){
        if(root==NULL) return;
        
        swap(root->left,root->right);
        dfs(root->left);
        dfs(root->right);
    }
    void mirror(Node* node) {
        // code here
        dfs(node);
    }
};
