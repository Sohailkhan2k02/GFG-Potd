class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        set<char> st;
        for(auto it: s) st.insert(it);
        
        char swap1 = '#', swap2 = '#';
        
        for(auto it: s) {
            
            if(st.empty())  break;
            
            if(it == *st.begin())    st.erase(it);
            else if(it < *st.begin())   continue;
            else {
                
                swap1 = *st.begin();
                swap2 = it;
                break;
            }
        }
        
        if(swap1 == '#' || swap2 == '#')    return s;
        
        for(auto &it: s) {
            
            if(it == swap1) it = swap2;
            else if(it == swap2)    it = swap1;
        }
        
        return s;
    }
};
