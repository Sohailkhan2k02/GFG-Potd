/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // code here
        if(root1->data!=root2->data) return false;
        unordered_map<int, int>mpp;
        queue<Node*>q1, q2;
        
        q1.push(root1);
        q2.push(root2);
        
        
        while(!q1.empty()){
            int sz=q1.size();
            while(sz--){
                Node* node=q1.front();
                q1.pop();
                if(node->left){
                    q1.push(node->left);
                    mpp[node->left->data]++;
                }
                if(node->right){
                    q1.push(node->right);
                    mpp[node->right->data]++;
                }
            }
            sz=q2.size();
            while(sz--){
                Node* node=q2.front();
                q2.pop();
                if(node->left){
                    q2.push(node->left);
                    mpp[node->left->data]--;
                    if(mpp[node->left->data]<0) return false;
                    else if(mpp[node->left->data]==0) mpp.erase(node->left->data);
                }
                if(node->right){
                    q2.push(node->right);
                    mpp[node->right->data]--;
                    if(mpp[node->right->data]<0) return false;
                    else if(mpp[node->right->data]==0) mpp.erase(node->right->data);
                }
            }
            if(!mpp.empty()) return false;
        }
        
        return true;
    }
};
