class Solution {
  public:
    int countSubstring(string& s) {
        // Code Here
        int count = 0;
        vector<int>mp1(s.size()*2+5 , 0) , mp2(s.size() *2 + 5);
        int ans = 0;
        int m = s.size();
        int curr = 0;
        mp1[m] = 1;
        for(auto i: s){
            if(i == '1'){curr+= mp1[count + m];count++; }
            else{  count--;curr-= mp1[count + m];}
            mp1[count +m]++;
            ans+= curr;
        }
        return ans;
    }
};
