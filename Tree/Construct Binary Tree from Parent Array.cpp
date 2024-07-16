//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
        int n=parent.size();
       unordered_map<int,Node*>mp;
       for(int i=0;i<n;i++) {
           mp[i] = new Node(i);
       }
       Node* root = NULL;
       for(int i=0;i<n;i++) {
           if(parent[i]==-1) root = mp[i];
           else {
               if(mp[parent[i]]->left==NULL) mp[parent[i]]->left = mp[i];
               else mp[parent[i]]->right = mp[i];
           }
       }
       return root;
    }
};
