//T.C : O(n)
//S.C : O(h)
class Solution {
  public:
    bool dfs(Node* root, int target, int sum){
        if(root==NULL) return false;
        sum+=root->data;
        
        if(root->left==NULL && root->right==NULL){
            return sum==target;
        }
        
        return dfs(root->left,target,sum)||dfs(root->right,target,sum);
    }
    bool hasPathSum(Node *root, int target) {
        // Your code here
        return dfs(root,target,0);
    }
};
