// T.C : O(n)
// S.C : O(n)
class Solution
{
    public:
    vector <int> diagonalSum(Node* root) {
        // Add your code here
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int val=0;
            int N=q.size();
            for(int i=0; i<N; i++){
                Node* node=q.front();
                q.pop();
                
                while(node){
                    val+=node->data;
                    if(node->left){
                        q.push(node->left);
                    }
                    node=node->right;
                }
            }
            ans.push_back(val);
        }
        return ans;
    }
};
