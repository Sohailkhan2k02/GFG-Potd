/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    int solve(Node* root, int& ans) {
        // Base Case
        if(root == NULL)  return 0;
        if(root->left == NULL && root->right == NULL)  return root->data;
        
        // LRN
        int lSub = solve(root->left, ans);
        int rSub = solve(root->right, ans);
        
        // 3 case ho skta h
        // case1: jiska dono leaf node h
        if(root->left != NULL && root->right != NULL) {
            ans = max(ans, lSub+rSub+root->data);
            return max(lSub, rSub) + root->data;
        }
        
        // case2: sirf root ke left part ka leaf node ho to
        if(root->left != NULL) {
            return lSub+root->data;
        }
        
        // Case3: sirf root ke right part ka leaf node ho to
        if(root->right != NULL) {
            return rSub+root->data;
        }
    }
    int maxPathSum(Node *root) {
        // Abhi Code Karo
        // Solve using Post Order Traversal LRN
        int ans = INT_MIN;
        
        solve(root, ans);
        
        if(ans == INT_MIN) {
            return -1;
        }
        return ans;
    }
};
