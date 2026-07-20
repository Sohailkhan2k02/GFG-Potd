class TrieNode {
    public:
    
    TrieNode* child[26];
    int freq;
    
    TrieNode() {
        freq = 0;
        
        for (int i=0; i<26; i++) {
            child[i] = NULL;
        }
    }
};

class Solution {
  public:
  
    TrieNode* root = new TrieNode();
    
    void insert(string& word) {
        
        TrieNode* curr = root;
        
        for (char& ch : word) {
            int idx = ch - 'a';
            
            if (curr->child[idx] == NULL) {
                curr->child[idx] = new TrieNode();
            }
            
            curr = curr->child[idx];
            curr->freq++;
        }
    }
    
    string getPrefix(string& word) {
        
        TrieNode* curr = root;
        string ans = "";
        
        for (char& ch : word) {
            int idx = ch - 'a';
            
            curr = curr->child[idx];
            ans += ch;
            
            if (curr->freq == 1)  {
                return ans;
            }
        }
        
        return ans;
    }
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        vector<string> ans;
        
        for (string& s : arr) {
            insert(s);
        }
        
        for (string& s : arr) {
            ans.push_back(getPrefix(s));
        }
        
        return ans;
    }
};
