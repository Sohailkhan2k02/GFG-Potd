//T.C : O(n)
//S.C : O(n)
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>res;
    	if(root==NULL){
    	    return res;
    	}
    	queue<pair<Node*, int>> q;
        q.push({root, root->data});
        int level = 1;
        
        while (!q.empty()) {
            int N = q.size();
            vector<int>ans;
            
            while (N--) {
                Node* node = q.front().first;
                int val = q.front().second;
                q.pop();
                
                ans.push_back(node->data);
                
                // if(node->left==NULL && node->right==NULL){
                //     res.push_back(node->data);
                // }
                
                // if (level % 2 == 0) {
                //     if (node->left){
                //         q.push({node->left, node->left->data});
                //     }
                //     if (node->right){
                //         q.push({node->right, node->right->data});
                //     }
                // } else {
                //     if (node->right){
                //         q.push({node->right, node->right->data});
                //     }
                //     if (node->left){
                //         q.push({node->left, node->left->data});
                //     }
                
                if(node->left){
                    q.push({node->left,node->left->data});
                }
                if(node->right){
                    q.push({node->right,node->right->data});
                }
            }
            if(level%2==0){
                reverse(ans.begin(),ans.end());
            }
            for(int i=0; i<ans.size(); i++){
                res.push_back(ans[i]);
            }
            level++;
        }
        
        return res;
    }
};
