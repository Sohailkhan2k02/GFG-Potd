//T.C : O(n)
//S.C : O(n)
/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty()){
            vector<int>temp;
            int N=q.size();
            while(N--){
                Node* node=q.front(); q.pop();
                temp.push_back(node->data);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
