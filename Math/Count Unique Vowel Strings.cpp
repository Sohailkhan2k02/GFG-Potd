class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                mp[s[i]]++;
        }
        int count = mp.size();
        if(count == 0)
            return 0;
        int part1 = 1;
        for(int i = 1; i <= count; i++)
        {
            part1 *= i;
        }
        int part2=1;
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            part2 *= itr->second;
        }
        return part1*part2;
    }
};
