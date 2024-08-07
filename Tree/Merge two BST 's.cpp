//APPROACH -1 
//T.C : O(n+m)*log(n+m)
//S.C : O(n+m)+O(height of root1)+O(height of root2)
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void postorder(Node *root,vector<int>&r){
        if(root==NULL){
            return;
        }
        
        postorder(root->left,r);
        postorder(root->right,r);
        r.push_back(root->data);
    }
    void merge(vector<int>&res, int s, int e){
        vector<int>temp;
        int m=s+(e-s)/2;
        int i=s,j=m+1;
        while(i<=m && j<=e){
            if(res[i]<=res[j]){
                temp.push_back(res[i++]);
            }
            else{
                temp.push_back(res[j++]);
            }
        }
        while(i<=m) temp.push_back(res[i++]);
        while(j<=e) temp.push_back(res[j++]);
        
        for(int i=0; i<temp.size(); i++){
            res[i+s]=temp[i];
        }
    }
    void mergeSort(vector<int>&res, int s, int e){
        if(s<e){
            int m=s+(e-s)/2;
            mergeSort(res,s,m);
            mergeSort(res,m+1,e);
            merge(res,s,e);
        }
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int>r1,r2,res;
        postorder(root1,r1);
        postorder(root2,r2);
        for(auto i:r1) res.push_back(i);
        for(auto i:r2) res.push_back(i);
        mergeSort(res,0,res.size()-1);
        return res;
    }
};

//APPROACH -2
//T.C : O(n+m)
//S.C : O(n+m)+O(height of root1)+O(height of root2)
class Solution {
  public:
    void pushLeft(Node* root, stack<Node*>& s) {
        while (root != NULL) {
            s.push(root);
            root = root->left;
        }
    }
    
    vector<int> merge(Node* root1, Node* root2) {
        stack<Node*> s1, s2;
        vector<int> result;
    
        pushLeft(root1, s1);
        pushLeft(root2, s2);
    
        while (!s1.empty() || !s2.empty()) {
            stack<Node*>* s;
            if (s1.empty()) {
                s = &s2;
            } else if (s2.empty()) {
                s = &s1;
            } else {
                if (s1.top()->data <= s2.top()->data) {
                    s = &s1;
                } else {
                    s = &s2;
                }
            }
            
            Node* n = s->top();
            s->pop();
            result.push_back(n->data);
    
            pushLeft(n->right, *s);
        }
    
        return result;
    }
};
