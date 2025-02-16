//T.C : O(n)
//S.C : O(n)
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    void preorder(vector<int>&ans,Node *root)
    {
        if(root==NULL)
        return ;
        
       
        preorder(ans,root->left);
         ans.push_back(root->data);
        preorder(ans,root->right);
    }
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int>ans;
        preorder(ans,root);
        
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       return NULL;
    }



};
