class Solution {
  public:
    string s = "";
    stack<char> st;
    void append(char x) {
        // append x into document
        s += x;
    }

    void undo() {
        // undo last change
        char ch = s.back();
        st.push(ch);
        s.pop_back();
    }

    void redo() {
        // redo changes
        char ch = st.top();
        st.pop();
        s += ch;
    }

    string read() {
        // read the document
        return s;
    }
};
