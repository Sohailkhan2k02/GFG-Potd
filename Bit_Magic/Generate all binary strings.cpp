class Solution {
  public:
    void fill(int i, int n, vector <string>& store, string& curr){
        if(i > n) return;
        
        curr.push_back('0');
        if(i == n) store.push_back(curr);
        fill(i+1, n, store, curr);
        curr.pop_back();
        
        curr.push_back('1');
        if(i == n) store.push_back(curr);
        fill(i+1, n, store, curr);
        curr.pop_back();
    }
  
    vector<string> binstr(int n) {
        vector <string> store;
        string curr;
        fill(1, n, store, curr);
        
        return store;
    }
};
