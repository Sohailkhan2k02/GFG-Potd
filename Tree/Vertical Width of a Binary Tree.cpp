//T.C : O(n)
//S.C : O(h)
class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int mini=INT_MAX;
    int maxi=INT_MIN;
    void traversal(Node*root,int i){
        if(root==NULL){
            return;
        }
        
        mini=min(mini,i);
        maxi=max(maxi,i);
        
        traversal(root->left,i-1);
        traversal(root->right,i+1);
    }
    
    int verticalWidth(Node* root) {
        
        if(root==NULL){
            return 0;
        }
          
          mini=INT_MAX;
          maxi=INT_MIN;
         traversal(root,0);
         return (maxi-mini)+1;
    }
};
