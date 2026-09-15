/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        // code here
        queue<Node*> q;
        q.push(root);
        
        int ans = 0;
        int level = 1;
        while(!q.empty() && level <= k) {
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                Node *node = q.front(); q.pop();
                
                if(!node->left && !node->right) {
                    if(k < level) return ans;
                    ans++;
                    k -= level;
                }
                else {
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            
            level++;
        }
        
        return ans;
    }
};
