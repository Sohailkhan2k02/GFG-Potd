class Solution {
  public:
    vector<string> h1, h2;

    void recursion1(int n, string s) {
        if (s.size() == n) {
            h1.push_back(s);
            return;
        }
        if (s.empty() || s.back() == '0') {
            s.push_back('1');
            recursion1(n, s); 
            s.pop_back();
        }
        s.push_back('0');
        recursion1(n, s); 
        s.pop_back();
    }

    void recursion2(int n, string s) {
        if (s.size() == n) {
            h2.push_back(s);
            return;
        }
        if (s.empty() || s.back() == '0') {
            s.push_back('1');
            recursion2(n, s);  
            s.pop_back();
        }
        s.push_back('0');
        recursion2(n, s);  
        s.pop_back();
    }

    int countStrings(int n) {
        recursion1(n / 2, "");
        recursion2(n - n / 2, "");

        int f0 = 0, f1 = 0;
        int s0 = 0, s1 = 0;

        for (auto it : h1) {
            if (it.back() == '1')
                f1++;
            else
                f0++;
        }

        for (auto it : h2) {
            if (it.front() == '1')
                s1++;  
            else
                s0++;  
        }

        int ans = f1 * s0 + f0 * s1 + f0 * s0;
        return ans;
    }
};
