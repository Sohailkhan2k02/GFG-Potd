/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int dfs(Node * root , unordered_map<Node * , int > & dp){
        if(!root) return 0;
        if(dp[root] != 0) return dp[root];
        int nt = dfs(root->left,dp)+dfs(root->right,dp);
        int tk = root->data;
        
        if(root->left) tk+=dfs(root->left->left,dp)+dfs(root->left->right,dp);
        if(root->right) tk+=dfs(root->right->left,dp)+dfs(root->right->right,dp);
        
        return dp[root]=max(tk,nt);
    }
    int getMaxSum(Node *root) {
        // code here
        unordered_map<Node*,int> dp;
        return dfs (root,dp);
    }
};
