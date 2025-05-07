//T.C : O(n)
//SmC : O(n)
class Solution {
public:
    void ways(Node* root,vector<int>&cur,vector<vector<int>>& result) {
        if (root==nullptr) 
            return;
        cur.push_back(root->data);
        if(root->left==nullptr && root->right==nullptr) 
            result.push_back(cur);
         else {
            ways(root->left,cur,result);
            ways(root->right,cur,result);
        }
        
        cur.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>result;
        vector<int>cur;
        ways(root,cur,result);
        return result;
    }
};
