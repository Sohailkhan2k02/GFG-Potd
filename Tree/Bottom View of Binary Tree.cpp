//T.C: O(n)
//S.C: O(n)
class Solution {
  public:
    map<int,pair<int,int>>mp;
    void solve(Node* root,int x,int y){
        if(root==NULL) return ;
        if(mp.find(x)!=mp.end()){
             if(mp[x].second<=y){
                 mp[x]={root->data,y};
             }
        }
        else{
            mp[x]={root->data,y};
        }
        solve(root->left,x-1,y+1);
        solve(root->right,x+1,y+1);
    }
    vector <int> bottomView(Node *root) {
          solve(root,0,0);
          vector<int>ans;
          for(auto it:mp) ans.push_back(it.second.first);
          return ans;
    }
};
