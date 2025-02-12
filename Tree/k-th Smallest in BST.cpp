//T.C : O(n)
//S.C : O(n)
/*Complete the function below

struct Node {
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
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        stack<Node*> st;
        Node* curr = root;
        int count = 0;

        while (curr != NULL || !st.empty()) {
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left; // Traverse left
            }
            curr = st.top();
            st.pop();
            count++;

            if (count == k) return curr->data; // Found k-th smallest

            curr = curr->right; // Move to right subtree
        }

        return -1; // k is greater than number of nodes in BST
    }
};
