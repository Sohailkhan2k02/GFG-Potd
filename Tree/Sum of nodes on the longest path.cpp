/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int maxLen, maxSum;
  
    void solve(Node* node, int len, int sum){
        if(!node) return;
        len+=1;
        sum+=node->data;
        if(!node->left && !node->right){
            if(len>maxLen){
                maxSum=sum;
                maxLen=len;
            }else if(len==maxLen){
                maxSum=max(maxSum, sum);
            }
            return;
        }
        solve(node->left, len, sum);
        solve(node->right, len, sum);
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        maxLen=0, maxSum=0;
        solve(root, 0, 0);
        return maxSum;
    }

};
