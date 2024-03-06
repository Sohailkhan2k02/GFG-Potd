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

//APPROACH 2 // RABIN CARP ALGO
//T.C: O(n+m)
//S.C: O(n+m)

class Solution
{
public:
    vector <int> search(string pattern, string text)
    {
        const int p = 31;
        const int m = 1e9 + 7;

        int pat = pattern.size(), txt = text.size();

        vector<long long> p_pow(max(pat, txt));
        p_pow[0] = 1;
        for(int i = 1; i < (int)p_pow.size(); i++)
            p_pow[i] = (p_pow[i - 1] * p) % m;

        vector<long long> hash_txt(txt + 1, 0);
        for(int i = 0; i < txt; i++)
            hash_txt[i + 1] = (hash_txt[i] + (text[i] - 'a' + 1) * p_pow[i]) % m;

        long long hash_pat = 0;
        for(int i = 0; i < pat; i++)
            hash_pat = (hash_pat + (pattern[i] - 'a' + 1) * p_pow[i]) % m;

        vector<int> occurences;
        for(int i = 0; i + pat - 1 < txt; i++) {
            long long cur_hash = (hash_txt[i + pat] - hash_txt[i] + m) % m;
            if(cur_hash == hash_pat * p_pow[i] % m)
                occurences.push_back(i + 1);
        }

        return occurences;
    }
};
