// User function Template for C++

class Solution {
  public:
 int Beauty(int st, string s, int n){
        int mem[26]={0},ans = 0;
        for(int i=st; i<n; i++)
        {
            char ch = s[i];
            mem[ch-'a']++;
            int min=INT_MAX, max=INT_MIN;
            for(int j=0; j<26; j++){
                if(mem[j]>0){
                    if(min>mem[j]) min = mem[j];
                    if(max<mem[j]) max = mem[j];
                }
            }
            ans += max - min;
        }
        return ans;
    }

    int beautySum(string s) {
        // Your code goes here
        int ans = 0,n = s.length();
        for(int i=0; i<n; i++)ans += Beauty(i, s, n);
        return ans;
    }

};
