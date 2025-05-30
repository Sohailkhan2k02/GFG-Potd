// User function Template for C++
/*
//Structure of the Node of the BST is as
struct Node {
    int key;
    Node* left, *right;
};


   'N' is the element
   'size' is the total element in BST
  */

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
