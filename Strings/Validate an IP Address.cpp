//T.C : O(n)
//S.C : O(n)
class Solution {
  public:
    int f(string& ip, char d){
        stringstream ss(ip);
        string token;
        int cnt = 0;
        while (getline(ss, token, d)) {
            cnt++;
        }
        return cnt;
    }
    int isValid(string queryIP){
        // code here
        int c1=f(queryIP,'.');
        // cout<<c2;
        if(c1==4){
            stringstream ss(queryIP);
            string token;
            while(getline(ss,token,'.')){
                if(token.empty() || token.size()>3 || token.size()>1 && token[0]=='0') return false;
                for(int i=0; i<token.size(); i++){
                    if(token[i]<'0' || token[i]>'9') return false;
                }
                if(stoi(token)>255) return false;
            }
            if(queryIP.back()=='.') return false;
            return true;
        }
        return false;
    }
};
