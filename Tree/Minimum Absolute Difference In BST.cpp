//T.C : O(n)
//S.C : O(1)
class Solution
{
    public:
    // void inorder(Node* root,vector<int>&v){
    //     if(root==NULL) return;
    //     if(root->left){
    //         inorder(root->left,v);
    //     }
    //     v.push_back(root->data);
    //     if(root->right){
    //         inorder(root->right,v);
    //     }
    // }
    // int absolute_diff(Node *root)
    // {
    //     //Your code here
    //     vector<int>vec;
    //     inorder(root,vec);
    //     int mini=INT_MAX;
    //     for(int i=1; i<vec.size(); i++){
    //         mini=min(mini,abs(vec[i]-vec[i-1]));
    //     }
    //     return mini;
        
    // }
    int diff=INT_MAX;
    void f(Node * root,Node * &prev){
        
        if(root==NULL) return;
        f(root->left,prev);
        if(prev!=NULL && diff>abs(prev->data-root->data)){
            diff=abs(prev->data-root->data);
        }
        prev=root;
        f(root->right,prev);
    }
    int absolute_diff(Node *root)
    {
       
        Node* prev=NULL;
        f(root,prev);
        return diff;
        //Your code here
    }
};
