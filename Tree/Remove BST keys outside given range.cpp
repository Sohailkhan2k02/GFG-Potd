/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        if(root==NULL){
            return NULL;
        }
        if(root->data<l){
            return removekeys(root->right,l,r);
        }
        if(root->data>r){
            return removekeys(root->left,l,r);
        }
        root->left=removekeys(root->left,l,r);
        root->right=removekeys(root->right,l,r);
        return root;
    }
};
