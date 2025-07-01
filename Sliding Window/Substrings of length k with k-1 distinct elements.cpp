//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char,int> map;
        int n = s.length();
        int i = 0;
        int j = 0;
        int count = 0;
        
        while(j < n){
            map[s[j]]++;
            
            if(j-i+1 == k){
                if(map.size() == k-1){
                    count++;
                }
                map[s[i]]--;
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        
        return count;
    }
};
