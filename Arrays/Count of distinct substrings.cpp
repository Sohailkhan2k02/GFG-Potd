class Solution {
  public:
    struct TrieNode{
    	TrieNode* child[26];
    	TrieNode(){
    		for(int c=0;c<26;c++)
                child[c]=NULL;
    	}
    };
    int countSubs(string& s) {
       TrieNode* root=new TrieNode();
       int n=s.size(),ans=0;
       for(int i=0;i<n;i++){
           TrieNode* curr=root;
           for(int j=i;j<n;j++){
               int req=s[j]-'a';
               if(curr->child[req]==NULL){
                   ans++;
                   curr->child[req]=new TrieNode();
               }
               curr=curr->child[req];
           }
       }
       return ans;
    }
};
