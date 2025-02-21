//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    bool isBalanced(string& x) {
        // code here
        stack<char> s;
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[')
            s.push(x[i]);
            
        else if (x[i] == ')') {
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
            
        } else if (x[i] == '}') {
            if (s.empty() || s.top() != '{')
                return false;
            s.pop();
        } else if (x[i] == ']') {
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
        }
    }
    return s.empty();
    }
};
