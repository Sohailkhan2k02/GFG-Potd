//T.C : O(n)
//S.C : O(n)
/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        stack<Node*>s1,s2;
    vector<int>res;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        if(!s1.empty()){
            while(!s1.empty()){
                Node* temp=s1.top();
                s1.pop();
                res.push_back(temp->data);
                if(temp->right){
                    s2.push(temp->right);
                }
                if(temp->left){
                    s2.push(temp->left);
                }
            }
        }
        else{
            while(!s2.empty()){
                Node* temp=s2.top();
                s2.pop();
                res.push_back(temp->data);
                if(temp->left){
                    s1.push(temp->left);
                }
                if(temp->right){
                    s1.push(temp->right);
                }
            }
        }
    }
    return res;
    }
};
