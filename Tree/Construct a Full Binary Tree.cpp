/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {

    int i, j;
    Node* createRecursively(vector<int> &pre, vector<int> &preM) {
        Node* node = new Node(pre[i]);
        
        if(pre[i] == preM[j]) {
            j--;
            return node;
        }
        
        int rootVal = pre[i];
        
        i++;
        node->left = createRecursively(pre, preM);
        
        i++;
        node->right = createRecursively(pre, preM);
        
        if(rootVal == preM[j]) j--;
        
        return node;
    }
  public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        i = 0;
        j = preMirror.size() - 1;
        
        return createRecursively(pre, preMirror);
    }
};
