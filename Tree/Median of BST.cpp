/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
     int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    int findKth(Node* root, int& k) {
        if (!root) return -1;
        int left = findKth(root->left, k);
        if (left != -1) return left;
        k--;
        if (k == 0) return root->data;
        return findKth(root->right, k);
    }

    int findMedian(Node* root) {
        int total = countNodes(root);
        int k = (total + 1) / 2;
        return findKth(root, k);
    }
};
