//T.C : O(n)
//S.C : O(n)

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      vector<int>v;
      queue<Node*>q;
      q.push(root);
      while(!q.empty()){
          Node* front=q.front();
          q.pop();
          if(front==NULL){
              if(!q.empty()){
                  q.push(NULL);
              }
          }
          else{
              v.push_back(front->data);
              if(front->left!=NULL){
                  q.push(front->left);
              }
              if(front->right!=NULL){
                  q.push(front->right);
              }
          }
      }
      return v;
    }
};
