
// User function Template for C++

class Solution {
  public:
    struct trienode{
      trienode* left;
      trienode* right;
      int endVal=0;
    };
    
    void insert(trienode* root, int &num){
        trienode* pCrawl=root;
        for(int i=31; i>=0; i--){
            int ith_bit=((num>>i)&1);
            if(ith_bit==0){
                if(!pCrawl->left) pCrawl->left=new trienode();
                pCrawl=pCrawl->left;
            }else{
                if(!pCrawl->right) pCrawl->right=new trienode();
                pCrawl=pCrawl->right;
            }
        }
        pCrawl->endVal=num;
    }
  
    int maxXor(vector<int> &arr) {
        // code here
        trienode* root=new trienode();
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            insert(root, arr[i]);
        }
        
        int maxi=-1e9;
        
        for(int &num:arr){
            trienode* pCrawl=root;
            for(int i=31; i>=0; i--){
                int ith_bit=((num>>i)&1);
                if(ith_bit==1){
                    if(pCrawl->left) pCrawl=pCrawl->left;
                    else pCrawl=pCrawl->right;
                }else{
                    if(pCrawl->right) pCrawl=pCrawl->right;
                    else pCrawl=pCrawl->left;
                }
            }
            maxi=max(maxi, (num^pCrawl->endVal));
        }
        return maxi;
    }
};
