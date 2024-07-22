//T.C : O(n)
//S.C : O(n)
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int a;
    vector<int> ans(Node*ptr)
    {
        if(!ptr)
        {
            return {INT_MAX,INT_MIN,0};
        }
        vector<int>p=ans(ptr->left);
        vector<int>pt=ans(ptr->right);
         if(p[1]<ptr->data&&pt[0]>ptr->data)
        {
            a=max(a,1+p[2]+pt[2]);
            return {min(p[0],ptr->data),max(pt[1],ptr->data),1+p[2]+pt[2]};
        }
        return {INT_MIN,INT_MAX}; 
    }
    int largestBst(Node *root)
    {
        a=1;
        ans(root);
        return a;
        //Your code here
    }
};
