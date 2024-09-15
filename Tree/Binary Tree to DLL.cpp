//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
  
    void inorder(Node* root,vector<int>&ans){
        if(root==NULL)return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
  
    Node* bToDLL(Node* root) {
        // code here
        vector<int>ans;
        inorder(root,ans);
        Node* head=new Node(ans[0]);
        Node* t=head;
        
        for(int i=1;i<ans.size();i++){
            Node* n = new Node(ans[i]);
            t->right=n;
            n->left=t;
            t=t->right;
        }
        return head;
    }
};
