
// User function template for C++
class Trie {
  public:

    struct trienode{
        bool isEndWord;
        trienode *children[26];
    };
    
    trienode* getNode(){
        trienode* newNode=new trienode();
        newNode->isEndWord=false;
        for(int i=0; i<26; i++){
            newNode->children[i]=NULL;
        }
        return newNode;
    }
    
    trienode* root;

    Trie() {
        // implement Trie
        root=getNode();
    }

    void insert(string &word) {
        // insert word into Trie
        trienode *crawl=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                crawl->children[idx]=getNode();
            }
            crawl=crawl->children[idx];
        }
        crawl->isEndWord=1;
    }

    bool search(string &word) {
        // search word in the Trie
        trienode *crawl=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL){
                return false;
            }
            crawl=crawl->children[idx];
        }
        return crawl->isEndWord;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        trienode *crawl=root;
        for(char &ch:word){
            int idx=ch-'a';
            if(crawl->children[idx]==NULL) return false;
            crawl=crawl->children[idx];
        }
        return true;
    }
};
