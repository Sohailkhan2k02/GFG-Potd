class Cmp{
  public:
    bool operator()(string a, string b){
      if((a+b)<=(b+a)) return true;
      return false;
    }
};

class Solution {
  public:
    virtual string findLargest(vector<int> &arr) {
      priority_queue<string, vector<string>, Cmp> pq;
      for(int x: arr){
        pq.push(to_string(x));  
      }
      
      string ans="";
      while(!pq.empty()){
        if(ans!="" || pq.top() != "0")
          ans+=(pq.top());
        pq.pop();  
      }
      
      return ans==""? "0": ans;
    }
};
