//T.C : O(n)
//S.C : O(n)
class Solution
{
    public:
    
    /*You are required to complete below function */
    Node* LCA(Node* root, int x, int y, vector<int>&ans){
        if(root==NULL) return 0;
        if(root->data==x || root->data==y){
            ans.push_back(root->data);
            return root;
        }
        if(root->data>x && root->data>y){
            ans.push_back(root->data);
            return LCA(root->left,x,y,ans);
        }
        if(root->data<x && root->data<y){
            ans.push_back(root->data);
            return LCA(root->right,x,y,ans);
        }
        ans.push_back(root->data);
        return root;
    }
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        vector<int>ans;
        Node* Ancestor=LCA(root,x,y,ans);
        if(k==1){
            return Ancestor->data;
        }
        int n=ans.size();
        if(n<k){
            return -1;
        }
        return ans[n-k];
    }
};
