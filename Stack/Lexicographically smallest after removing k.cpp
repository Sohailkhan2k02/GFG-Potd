class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n = s.size();

 

        if ((n & (n - 1)) == 0)

            k /= 2;

        else

            k *= 2;

 

        if (k >= n)

            return "-1";

 

        vector<char> st;

 

        for (char ch : s) {

            while (!st.empty() && k > 0 && st.back() > ch) {

                st.pop_back();

                k--;

            }

 

            st.push_back(ch);

        }

 

        while (k > 0) {

            st.pop_back();

            k--;

        }

 

        string ans(st.begin(), st.end());


        return ans.empty() ? "-1" : ans;
        
    }
};
