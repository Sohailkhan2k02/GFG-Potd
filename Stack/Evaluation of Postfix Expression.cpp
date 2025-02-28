//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
         stack<int>s;
        for(int i=0;i<arr.size();i++){
            int a=0,b=0,result;
            if(!(arr[i]=="*" || arr[i]=="+" || arr[i]=="-" || arr[i]=="/" )) {
                s.push(stoi(arr[i]));
            }
            else {
                a=s.top();
                s.pop();
                b=s.top();
                s.pop();
                if(arr[i]=="*") result=b*a;
                else if(arr[i]=="+") result=b+a;
                else if(arr[i]=="-") result=b-a;
                else if(arr[i]=="/") result=b/a;
                s.push(result);
            }
        }
        return s.top();
    }
};
