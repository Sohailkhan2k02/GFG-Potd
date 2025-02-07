//T.C : O(n)
//S.C : O(n)
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        if (root == nullptr) {
            return vector<int>();
        }
        vector<int> path1 = inOrder(root->left);
        path1.push_back(root->data);
        vector<int> path2 = inOrder(root->right);
        path1.insert(path1.end(), path2.begin(), path2.end());

        return path1;
    }
};
