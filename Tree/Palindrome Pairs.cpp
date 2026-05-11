class trie{
    public:
        vector<int>ind;
        vector<trie*>vec;
        trie(){
            vec.resize(26 , NULL);
        }
};

class Solution {
  public:
    void process1(trie * t , vector<string>& st){
        int ct = -1;
        for(auto i: st){
            ct++;
            trie* head = t;
            for(auto j: i){
                int h = j-'a';
                if(head->vec[h]== NULL)head->vec[h] = new trie;
                head = head->vec[h];
            }
            head->ind.push_back(ct);
        }
        return;
    }
    
    void process2(trie * t , vector<string>& st){
        int ct = -1;
        for(auto i: st){
            ct++;
            reverse(i.begin() , i.end());
            trie* head = t;
            for(auto j: i){
                int h = j-'a';
                if(head->vec[h]== NULL)head->vec[h] = new trie;
                head = head->vec[h];
            }
            // head->poss = true;
            head->ind.push_back(ct);
        }
        return;
    }
  
    bool palindromePair(vector<string>& arr) {
        // Code here
        trie *t1 = new trie , *t2 = new trie;
        process1(t1 , arr);
        process2(t2 , arr);
        int ct = -1;
        for(auto i: arr){
            ct++;
            trie* head = t2;
            string s= i;
            reverse(s.begin() , s.end());
            for(auto j: i){
                int h = j-'a';
                if(head->vec[h] == NULL){
                    break;
                }else head = head->vec[h];
                s.pop_back();
                if(head->ind.size()){
                    if(head -> ind.size() == 1 && head -> ind[0] == ct)break;
                    int a = 0 , b = s.size()-1;;
                    while(a <=b){
                        if(s[a] != s[b])break;
                        a++;
                        b--;
                    }
                    if(a > b)return true;
                }
                
            }
        }
        ct = -1;
        
        for(auto i: arr){
            ct++;
            trie* head = t1;
            
            string s= i;
            reverse(i.begin() , i.end());
            for(auto j: i){
                int h = j-'a';
                if(head->vec[h] == NULL){
                    break;
                }else head = head->vec[h];
                s.pop_back();
                if(head->ind.size()){
                    if(head -> ind.size() == 1 && head -> ind[0] == ct)break;
                    int a = 0 , b = s.size()-1;;
                    while(a <=b){
                        if(s[a] != s[b])break;
                        a++;
                        b--;
                    }
                    if(a > b)return true;
                }
                
            }
        }
        return false;
        
        
    }
};
