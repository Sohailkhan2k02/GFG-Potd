/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int ans;
    void solve(Node* root){
        if(!root){
            return;
        }
        solve(root->left);
        ans++;
        solve(root->right);
    }
    
    int getSize(Node* root) {
        ans = 0;
        solve(root);
        return ans;
    }
};
