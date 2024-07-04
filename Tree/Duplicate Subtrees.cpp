//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    string solve(Node* root,unordered_map<string,int> &mp,vector<Node*> &ans)
    {
        if(root==NULL)
            return "0";
            
        string temp="";
        string l=solve(root->left,mp,ans);
        string r=solve(root->right,mp,ans);
        
        string t=to_string(root->data);
        temp=l+r+t;
        
        if(mp[temp]==1)
            ans.push_back(root);
        
        mp[temp]++;
        return temp;
    }
  
    vector<Node*> printAllDups(Node* root) 
    {
        unordered_map<string,int> mp;
        vector<Node*> ans;
        solve(root,mp,ans);
        return ans;
    }
};
