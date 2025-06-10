class Solution {
  public:
    int countStrings(string &s) {
        // code here
        int n=s.length();
        unordered_map<char,int>map;
        for(auto i:s)
        map[i]++;
        int ans=(n*(n-1))/2;
        int diff=0;
        for(auto i:map)
        {
            if(i.second>1)
            {
                int len=i.second;
                diff+=(len*(len-1))/2;
            }
        }
        if(diff>0)
        return ans-diff+1;
        return ans;
    }
};
