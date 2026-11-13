

class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    vector<int>v;
    bool f(Node* node, int x){
        if(node==NULL){
            return false;
        }
        if(node->data==x){
            return true;
        }
        if(node->data>x){
            return f(node->left, x);
        }
        return f(node->right, x);
    }
    void inOrder(Node* root1, Node* root2){
        if(root1==NULL){
            return;
        }
        inOrder(root1->left, root2);
        if(f(root2, root1->data))
            v.push_back(root1->data);
        inOrder(root1->right, root2);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     inOrder(root1, root2);
     return v;
    }
};

