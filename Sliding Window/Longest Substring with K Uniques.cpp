//User function template for C++
//T.C : O(n)
//S.C : O(n)
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int n=s.size();
    unordered_map<char,int>mpp;
    int i=0,j=0;
    int maxi=-1;
    while(j<n){
        mpp[s[j]]++;
        if(mpp.size()<k){
            j++;
        }
        else if(mpp.size()==k){
            maxi=max(maxi,j-i+1);
            j++;
        }
        else if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
    }
};
