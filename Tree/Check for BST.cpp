//T.C : O(n)
//S.C : O(h)
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool validate(Node* root , int min , int max)
    {
        if(root ==NULL) return true;
        
        if(root -> data >=max || root -> data <= min) return false;
        
        return validate(root -> left,min,root -> data) && 
        validate(root -> right,root -> data,max);
    }
    bool isBST(Node* root) {
       return validate(root,INT_MIN,INT_MAX);
    }
};
