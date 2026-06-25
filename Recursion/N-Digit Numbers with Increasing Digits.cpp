class Solution {
  vector<int>ans;
  public:
   
    void find(int n,int last,int num){
        
        if(n==0){
            ans.push_back(num);
            return;
        }
        
        for(int i=last+1;i<=9;i++){
            num*=10;
            num+=i;
            find(n-1,i,num);
            num/=10;
        }
        
        
    }
    
    vector<int> increasingNumbers(int n) {
        // code here
        if(n>=10)return {};
        if(n==1)ans.push_back(0);
        find(n,0,0);
        return ans;
    
    }
};
