/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

using pri = pair<int, Node*>;
using vi = vector<int>;

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vi> ans;
        
        if (!root)
            return ans;
        
        queue<pri> q;
        map<int, vi> m;
        
        q.push({0, root});
        
        while (!q.empty()) {
            auto d = q.front().first;
            auto node = q.front().second;
            
            q.pop();
            
            m[d].push_back(node->data);
            
            if (node->left)
                q.push({d -1 , node->left});
            if (node->right)
                q.push({d + 1, node->right});
        }
        
        for (auto& [k, t] : m)
            ans.push_back(t);
        
        return ans;
    }
};
