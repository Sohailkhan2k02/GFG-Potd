// T.C:  O((n-m)*m)
// S.C: O(1)

class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
              vector<int>ans;
            int n = text.size();
            int m = pattern.size();
            
            for(int i=0;i<n;i++){
                bool ismatch = true;
                
                for(int j=0;j<m;j++){
                    if(text[i+j]!=pattern[j]){
                        ismatch = false;
                        break;
                    }
                }
                if(ismatch == true)
                    ans.push_back(i+1);
                
            }
            return ans;
        }
     
};
