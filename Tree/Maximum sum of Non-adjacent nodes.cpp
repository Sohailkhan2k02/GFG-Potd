//T.C : O(n)
//S.C : O(1)
// User function Template for C++

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> fun(Node* root){
        if(!root)
            return {0, 0};
        auto l = fun(root->left);
        auto r = fun(root->right);
        
        int include = (root->data)+(l.second)+(r.second);
        int exclude = max(l.first, l.second)+max(r.second, r.first);
        
        return {include, exclude};
    }
    
    int getMaxSum(Node *root) {
        // code here
        auto res = fun(root);
        return max(res.first, res.second);
    }
};
