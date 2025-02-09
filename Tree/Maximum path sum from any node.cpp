//T.C : O(n)
//S.C : O(n)
// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int result = INT_MIN;
    int dfs(Node* node)
    {
        if(!node)   return 0;
        int leftsub = dfs(node->left);
        int rightsub = dfs(node->right);
        int sides = max(leftsub + node->data, rightsub + node->data);
        int others = max(leftsub + rightsub + node->data, node->data);
        result = max(result, max(others, sides));
        return max(sides, node->data);
    }
    int findMaxSum(Node *root) {
        if( !root)  return 0;
        dfs(root);
        return result;
    }
};
