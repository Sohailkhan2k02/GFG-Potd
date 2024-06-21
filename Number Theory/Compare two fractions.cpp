//T.C :  O(len|str|)
//S.C : O(1)
class Solution {
  public:
    string compareFrac(string str) {
        int n=1;
        string a,b,c,d;
        for(char ch:str){
            if(ch=='/' || ch==' ' || ch==','){
                if(ch!=',')n++;
                continue;
            }
            if(n==1)a.push_back(ch);
            else if(n==2)b.push_back(ch);
            else if(n==3)c.push_back(ch);
            else d.push_back(ch);
        }
        double f1=stoi(a)*1.0/stoi(b);
        double f2=stoi(c)*1.0/stoi(d);
        return f1==f2?"equal":f1>f2?a+"/"+b:c+"/"+d;
    }
};
