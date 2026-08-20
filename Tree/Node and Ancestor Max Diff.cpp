/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
int f(Node* root, int &diff){
    if(root==NULL)return INT_MAX;
    
    int left = f(root->left, diff);
    int right = f(root->right, diff);
    
    int ans= min(left,right);
    diff= max(diff, root->data-ans);
    return min(ans, root->data);
}
int maxDiff(Node* root)
{
    int diff= INT_MIN;
    f(root,diff);
    return diff;
}
