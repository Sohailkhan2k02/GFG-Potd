//T.C : O(n+m)
//S.C : O(n)
class Solution {
  public:
  void computelps(string &pat, vector<int>&lps){
            int m=pat.size();
            int len=0;
            lps[0]=0;
            int i=1;
            while(i<m){
                if(pat[i]==pat[len]){
                    len++;
                    lps[i]=len;
                    i++;
                }
                else{
                    if(len!=0){
                        len=lps[len-1];
                    }else{
                        lps[i]=0;
                        i++;
                    }
                }
            }
        }
    vector<int> search(string& pat, string& txt) {
        // code here
        int n=txt.size(),m=pat.size();
            vector<int>res;
            
            vector<int>lps(m,0);
            computelps(pat, lps);
                        
            int i=0;
            int j=0;
            
            while(i<n){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                }
                if(j==m){
                    res.push_back(i-j); // if it is 0 base indexing then i-j but here is 1 base indexing
                    j=lps[j-1];
                }
                else if(txt[i]!=pat[j]){
                    if(j!=0){
                        j=lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
            }
            return res;
    }
};
