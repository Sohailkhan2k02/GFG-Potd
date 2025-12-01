class Solution {
  public:
    struct Trie{
        Trie* child[2];
        int cnt;
        Trie(){
            child[0]=child[1]=nullptr;
            cnt=0;
        }
    };

    Trie* root=new Trie();

    // Insert a number into trie
    void insert(int x){
        Trie* node=root;
        for (int i=15;i>=0;i--){
            int bit=(x>>i)&1;
            
            if(!node->child[bit]){
                node->child[bit]=new Trie();
            }
                
            node = node->child[bit];
            node->cnt++;
        }
    }

    // Query: count numbers already inserted such that (x XOR y) < k
    int query(int x,int k) {
        Trie* node=root;
        int res = 0;
        for (int i = 15;i>=0;i--){
            if(!node){
                break;
            }
            
            int xb=(x>>i) & 1;
            int kb=(k>>i) & 1;

            // Case: kb == 1 → add subtree where XOR bit = 0
            if (kb==1){
                int want = xb;  // XOR = 0 → bits same
                if (node->child[want]){
                    res+=node->child[want]->cnt;
                }
                    
                node=node->child[xb ^ 1];  // move to XOR = 1 branch
            } 
            else { // kb == 0 → must go only to XOR = 0 path
                int want = xb;
                node=node->child[want];
            }
        }
        return res;
    }

    int cntPairs(vector<int>& arr, int k) {
        int ans=0;
        for (int x : arr) {
            ans+=query(x, k); // count valid earlier pairs
            insert(x);
        }
        
        return ans;
    }
};
