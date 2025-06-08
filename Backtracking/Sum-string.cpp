class Solution {
public:
    string s_add(string a, string b) {
        string ans = "";
        int d = 0,i=a.size()-1,j =b.size()-1;
        while (i >= 0 || j >= 0 || d) {
            int c= d;
            if(i>=0) c+=a[i--]-'0';
            if(j>=0) c+=b[j--]-'0';
            ans.push_back(c % 10+'0');
            d=c/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool isValid(string s,int start,string a,string b) {
        while (start<s.size()) {
            string c=s_add(a, b);
            int len =c.length();
            if(start+len >s.size() || s.substr(start,len)!= c)
                return false;
            start+= len;
            a=b;
            b=c;
        }
        return true;
    }
    bool isSumString(string &s) {
        int n=s.length();
        for(int i =1; i<n; i++) {
            for (int j =1;i + j< n;j++) {
                string a=s.substr(0, i);
                string b=s.substr(i, j);
                if((a.length()> 1&& a[0]=='0') || 
                    (b.length()> 1&& b[0]=='0')) {
                    continue;
                }

                if(isValid(s,i+j,a,b))
                    return true;
            }
        }
        return false;
    }
};
