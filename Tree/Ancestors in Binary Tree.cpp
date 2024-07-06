//T.C : O(n)
//S.C : O(h)
class Solution {
  bool solve(Node* root, vector<int>& ans, int target){
        if(root==NULL) return false;
        if(root->data == target) return true;
        bool left = solve(root->left,ans,target);
        bool right = solve(root->right,ans,target);
        if(left || right){
            ans.push_back(root->data);
        }
        return left || right;
    }
  public:
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> ans;
        solve(root,ans,target);
        return ans;
    }
};
