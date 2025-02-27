//T.C : O(n)
//S.C : O(n)
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/


class Solution {
  public:
    stack<pair<int,int>>st;
    int mini=INT_MAX;
    Solution() {}
    void push(int x) {
        mini=min(mini,x);
        st.push({x,mini});
    }
    //each element in the stack stores {value, min_so_far}
    void pop() {
        if(st.empty())  return;
        st.pop();
        if(st.empty())
            mini=INT_MAX;
        else
            mini=st.top().second;
    }

    int peek() {
        if(st.empty())  return -1;
        return st.top().first;
    }
    int getMin() {
        if(st.empty())  return -1;
        return st.top().second;
    }
};
