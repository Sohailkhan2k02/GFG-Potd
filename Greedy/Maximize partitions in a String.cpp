//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
            
        }
        int end=0,cnt=0;;
        for(int i=0;i<n;i++)
        {
            end=max(mp[s[i]],end);
            if(i==end)
            {
                cnt++;
            }
            
        }
        return cnt;
    }
};
