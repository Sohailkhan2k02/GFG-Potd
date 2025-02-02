//T.C : O(n)
//S.C : O(recursive stack space)
//User function template for C++

/*
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
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(Node* node){
        // code here 
        if(node==NULL) return -1;
        return 1+max(height(node->left),height(node->right));
    }
};
