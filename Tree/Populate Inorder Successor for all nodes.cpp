//T.C : O(n)
//S.C : O(1)
class Solution {
  void inorder(Node* root, Node*& prev) {
        if (root == NULL) {
            return;
        }
        // Recur on the left subtree
        inorder(root->left, prev);
        // Process the current node
        if (prev != NULL) {
            prev->next = root;
        }
        prev = root;
        // Recur on the right subtree
        inorder(root->right, prev);
    }
public:
    void populateNext(Node* root) {
        Node* prev = NULL;
        inorder(root, prev);
    }
};
