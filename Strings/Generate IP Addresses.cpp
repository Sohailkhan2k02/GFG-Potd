class Solution {
  public:
    void solve(string t,int i,string &s,string temp,vector<string> &ans,int count)
  {
      int n=s.size();
      if(temp.size()>1 && temp[0]=='0')return ;
      if(temp.size()==3 && stoi(temp)>255)return ;
      if(i>n || count >4)return;
      t+=temp;
      if(count<4 && count>=1)t+='.';
      if(count==4 && i==n)
      {
          ans.push_back(t);
      }
      temp="";
      solve(t,i+1,s,temp+s[i],ans,count+1);
      if(i+1<n)solve(t,i+2,s,temp+s[i]+s[i+1],ans,count+1);
      if(i+2<n)solve(t,i+3,s,temp+s[i]+s[i+1]+s[i+2],ans,count+1);
      
  }
    vector<string> generateIp(string &s) {
        // code here
        int n=s.size();
        if(n>12)return {};
        string temp="";
        vector<string>ans;
        solve("",0,s,temp,ans,0);
        // for(auto it:ans)
        // {
        //     it=it.pop_back();
        // }
        return ans ;
        
}
};
