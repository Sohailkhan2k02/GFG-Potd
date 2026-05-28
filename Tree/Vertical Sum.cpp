/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution {
  public:
    vector<int> verticalSum(Node* root) {
        // code here
        map<int, vector<int>> mp;
        queue<pair<int, Node*>> q;
        
        q.push(make_pair(0, root));
        while(!q.empty()){
            pair<int, Node*> front= q.front();
            q.pop();
            int ver= front.first;
            Node* node= front.second;
            mp[ver].push_back(node->data);
            if(node->left){
                q.push(make_pair(ver-1, node->left));
            }
            if(node->right){
                q.push(make_pair(ver+1, node->right));
            }
        }
        vector<int> ans;
        for(auto i: mp){
            int sum=0;
            for(auto j: i.second){
                sum+=j;
            }
            ans.push_back(sum);
            sum=0;
        }
        return ans;
    }
};
