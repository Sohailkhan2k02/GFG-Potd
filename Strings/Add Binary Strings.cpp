//T.C : O(n+m)
//S.C : O(max(n,m)
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string ans = "";
        int n= s1.size()-1;
        int m = s2.size()-1;
        string carry = "";
        while(n >=0 && m >=0){
            
            if(s1[n] == '0' && s2[m]=='0'){
                if(carry == "1"){
                    ans = "1" + ans ;
                    carry= "0";
                }
                else{
                    ans = "0" + ans ;
                }
            }
            else if(s1[n] == '1' && s2[m]=='1'){
                if(carry=="1"){
                   ans = "1" + ans ;
                }
                else{
                    ans = "0" + ans ;
                }
                carry = "1";
            }
            else{
                if(carry== "1"){
                    ans = "0" + ans ;
                }
                else{
                   ans = "1" + ans ;
                }
            }
            n--;
            m--;
        }
        while(n>=0){
            if(carry== "1"){
                if(s1[n]=='1'){
                    ans = "0" + ans;
                }
                else{
                    ans = "1" + ans;
                    carry="0";
                }
            }
            else{
                ans = s1[n] + ans;
            }
            n--;
        }
        while(m>=0){
            if(carry== "1"){
                if(s2[m]=='1'){
                    ans = "0" + ans;
                }
                else{
                    ans = "1" + ans;
                    carry="0";
                }
            }
            else{
                ans = s2[m] + ans;
            }
            m--;
        }
        if(carry=="1"){
            ans = "1" + ans;
        }
        int count =0;
        while(ans[count]=='0')
            count++;
        ans.erase(0,count);
        return ans;
    }
};
