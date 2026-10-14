class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        vector<int>vec(s.size(), 0);
                for(auto it : roll){
                    vec[it-1] = vec[it-1]+1;
                }
                int sum = 0;
                for(int i = s.size()-1;i>=0;i--){
                    sum=(vec[i]+sum)%26;
                    if(s[i] + sum > 'z'){
                        int diff = (s[i] + sum) - 'z';
                        diff--;
                        s[i] = 'a' + (diff); 
                        continue;
                    }
                    s[i] += sum;
                }
                return s;
    }
};
