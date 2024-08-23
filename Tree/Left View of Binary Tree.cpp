//T.C: O(n)
//S.C: O(n)
void inorder(Node* root,vector<int>&res){
    if(root==NULL) return;

    inorder(root->left,res);
    res.push_back(root->data);
    inorder(root->right,res);
}
vector<int> leftView(Node *root)
{
   // Your code here
  vector<int> res;
    if(root == NULL) return res;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            if(i == 0) {
                res.push_back(curr->data);
            }
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return res;
}
