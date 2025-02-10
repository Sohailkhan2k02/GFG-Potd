//T.C : O(n)
//S.C : O(n)
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
int ans = 0;
    void solve(Node* root,int k,int sum,unordered_map<int,int> &mp) {
        if(root == NULL) {
            return ;
        }
        
        sum += root->data;
        
        if(mp.find(sum-k) != mp.end()) 
            ans += mp[sum-k];
            
            mp[sum]++;
            
            solve(root->left,k,sum,mp);
            solve(root->right,k,sum,mp);
            
            mp[sum]--;
        
    }
    int sumK(Node *root, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        
        solve(root,k,0,mp);
        
        return ans;
    }
};
