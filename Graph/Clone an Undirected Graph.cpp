//T.C : O(v+e)
//S.C : O(v+e)
// User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
  public:
    Node* cloneGraph(Node* node) {
        // code here
        if(!node) return NULL;
        unordered_map<Node*, Node*> mp;
        queue<Node*> q; 
        q.push(node);         
        mp[node] = new Node(node->val);
        while(!q.empty()){
            Node* tmp = q.front();
            q.pop();
            for(auto &x : tmp->neighbors){
                if(!mp.count(x)) mp[x] = new Node(x->val), q.push(x); 
                mp[x]->neighbors.push_back(mp[tmp]);
            }
        }
        return mp[node];
    }
};
