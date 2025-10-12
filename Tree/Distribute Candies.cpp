//User function Template for C++

/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
    int solve(Node *root,int &moves){
        if(!root){
            return 0;
        }
        int left = solve(root->left,moves);
        int right = solve(root->right,moves);
        moves+= abs(left) + abs(right);
        return root->key - 1 + left + right;
    }
    int distributeCandy(Node* root)
    {
        int moves=0;
        solve(root,moves);
        return moves;
    }

};
