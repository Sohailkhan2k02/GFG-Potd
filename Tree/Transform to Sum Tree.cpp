/* Structure for Tree Node
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
    void toSumTree(Node *root) {
        if(root == nullptr) return;
        int x = 0;
        if(root->left != nullptr){
            x += root->left->data;
            toSumTree(root->left);
            x += root->left->data;
        }
        if(root->right != nullptr){
            x += root->right->data;
            toSumTree(root->right);
            x += root->right->data;
        }
        root->data = x;
    }
};
