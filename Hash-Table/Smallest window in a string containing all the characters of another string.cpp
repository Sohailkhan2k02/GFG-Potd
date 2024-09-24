//T.C : O(n)
//S.C : O(n)
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n=s.size();
        if(p.size()>s.size()) return "-1";
        // unordered_map<char,int>mpp;
        int mpp[256]={0};
        for(auto i:p) mpp[i]++;
        int len=p.size();
        int j=0,i=0;
        int mini=INT_MAX,ind=-1;
        while(j<n){
            if(mpp[s[j]]>0){
                len--;
            }
            mpp[s[j]]--;
            while(len==0){
                if(mini>j-i+1){
                    mini=j-i+1;
                    ind=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0){
                    len++;
                }
                i++;
            }
            j++;
        }
        if(mini==INT_MAX) return "-1";
        return s.substr(ind,mini);
    }
};
