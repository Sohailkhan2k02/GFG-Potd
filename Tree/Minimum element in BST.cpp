//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        int mini=INT_MAX;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int N=q.size();
            int mnn=INT_MAX;
            while(N--){
                Node* node=q.front();
                q.pop();
                
                mnn=min(mnn,node->data);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            mini=min(mini,mnn);
        }
        return mini;
    }
};
