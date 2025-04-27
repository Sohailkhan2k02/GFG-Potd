//T.C : O(n)
//S.X : O(n)
class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        int n = s1.length(), m = s2.length();
    
        bool isNegative = false;
        if (s1[0] == '-' && s2[0] != '-') isNegative = true;
        if (s1[0] != '-' && s2[0] == '-') isNegative = true;
    
        string temp1 = "", temp2 = "";
        int startIdx = (s1[0] == '-') ? 1 : 0;
        for (int i = startIdx; i < n; i++) temp1.push_back(s1[i]);
        startIdx = (s2[0] == '-') ? 1 : 0;
        for (int i = startIdx; i < m; i++) temp2.push_back(s2[i]);
        s1 = temp1;
        s2 = temp2;
    
        string str = "";
        int index = -1;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != '0') {
                index = i;
                break;
            }
        }
        for (int i = index; i < s1.length(); i++) str.push_back(s1[i]);
        s1 = (index == -1) ? "0" : str;
    
        str = "";
        index = -1;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] != '0') {
                index = i;
                break;
            }
        }
        for (int i = index; i < s2.length(); i++) str.push_back(s2[i]);
        s2 = (index == -1) ? "0" : str;
    
        if (s1 == "0" || s2 == "0") return "0";
    
        n = s1.length();
        m = s2.length();
    
        string prod(n + m, '0');
    
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = (prod[i + j + 1] - '0') + mul;
                prod[i + j + 1] = (sum % 10) + '0';
                prod[i + j] += sum / 10;
            }
        }
    
        index = -1;
        for (int i = 0; i < prod.length(); i++) {
            if (prod[i] != '0') {
                index = i;
                break;
            }
        }
        str = "";
        for (int i = index; i < prod.length(); i++) str.push_back(prod[i]);
        prod = (index == -1) ? "0" : str;
    
        return isNegative ? "-" + prod : prod;
    }
};
