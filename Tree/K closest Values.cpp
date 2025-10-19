/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  int sz = 0;
    void solve(Node * root, int target, int k, map<int,priority_queue<int>> & mp)
    {
        if(!root)
        return;
        
        solve(root->left, target, k, mp);
        
        if(sz<k)
        {
            mp[abs(target-root->data)].push(root->data);
            sz++;
        }
        else
        {
            int largest = mp.rbegin()->first;
            if(abs(target-root->data)<=largest)
            {
                mp[abs(target-root->data)].push(root->data);
                mp[largest].pop();
                if(mp[largest].empty())
                mp.erase(largest);
            }
        }
        
        solve(root->right, target, k, mp);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        
        map<int,priority_queue<int>> mp;
        sz = 0;
        solve(root, target, k, mp);
        
        vector<int> res;
        
        for(auto it : mp)
            while(!mp[it.first].empty())
            {
                res.push_back(mp[it.first].top());
                mp[it.first].pop();
            }
        return res;
    }
};
