//T.C : O(n)
//S.C : O(n)
class Solution {
public:
void matchPairs(int n, char nuts[], char bolts[]) {
        // !,#,$,%,&,*,?,@,^ -> 0 1 2 3 4 5 6 7 8
        vector<int> mp(64, 0);
        for(int i = 0; i < n; i++)
        {
            mp[nuts[i] - '!']++;
        }
        int j = 0;
        for(int i = 0; i < 64; i++)
        {
            while(mp[i]!=0)
            {
                nuts[j] = static_cast<char>(i + 33);
                bolts[j] = static_cast<char>(i + 33);
                mp[i]--;
                j++;
            }
        }
    };
