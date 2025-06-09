/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution {
public:
    bool solve(Node *root, int mini, int maxi) {
        if(root == nullptr)
            return false;
            
        if(!root->left and !root->right)
            return mini == maxi;
        
        return solve(root->left, mini, root->data - 1) or solve(root->right, root->data + 1, maxi);
    }

    bool isDeadEnd(Node *root) {
        return solve(root, 1, 1e9);
    }
};
