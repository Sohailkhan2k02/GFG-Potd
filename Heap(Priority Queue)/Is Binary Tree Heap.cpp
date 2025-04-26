//T.C : O(n)
//S.C : O(1)
// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    pair<int,bool> solve(Node* tree,bool &cut){
        if(!tree) return {0,1};
        
        int d = tree->data;
        if(tree->left && tree->right){
            if(tree->left -> data <= d && tree->right->data <= d){
                pair<int,bool> l = solve(tree->left,cut);
                pair<int,bool> r = solve(tree->right,cut);
                
                if(l.second && r.second)
                    if(l.first == r.first || l.first-1 == r.first) return {l.first+1,1};
            }
        }
        else if(tree->left && !tree->right && !cut && tree->left->data <= d){
             cut= 1;
             pair<int,bool> l = solve(tree->left,cut);
             if(l.second && l.first==1){
                 return {l.first+1,1};
             } 
        } else if(!tree->left && !tree->right){
            return {1,1};
        } 
        return {0,0};
    }
    
  public:
    bool isHeap(Node* tree) {
        // code here
        bool cut = 0;
        
        return solve(tree,cut).second;
    }
};
