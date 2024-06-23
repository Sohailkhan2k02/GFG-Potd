//T.C: O(n)
//S.C : O(n)
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        int open=0;
        stack<int>close;
        vector<int>ans;
        for(int i=0;i<str.length();i++){
            if(str[i]=='('){
                open++;
                ans.push_back(open);
                close.push(open);
            }
            else if(str[i]==')'){
                ans.push_back(close.top());
                close.pop();
            }
        }
        return ans;
    }
};
