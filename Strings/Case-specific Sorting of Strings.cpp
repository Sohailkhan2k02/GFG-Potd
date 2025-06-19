//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string lower = "";
        string capital = "";
        
        for(int i = 0;i<s.size();i++){
            if(s[i]<='Z'){
                capital.push_back(s[i]);
            }
            else{
                lower.push_back(s[i]);
            }
        }
        
        sort(lower.begin(),lower.end());
        sort(capital.begin(),capital.end());
        
        
        for(int i = 0,j=0,k=0;i<s.size();i++){
            if(s[i]<='Z'){
                s[i] = capital[j];
                j++;
            }
            else{
                s[i] = lower[k];
                k++;
            }
        }
        
        return s;
    }
};
