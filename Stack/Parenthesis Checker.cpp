//T.C : O(n)
//S.C : O(n)
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        stack<char>st;
        for(auto c:s){
            if(c=='(' || c=='[' || c=='{') st.push(c);
            else{
                if(st.empty()) return false;
                if(st.top()!='(' && c==')' || st.top()!='[' && c==']' || st.top()!='{' && c=='}') return false;
                st.pop();
            }
        }
        return st.empty();
    }

};
