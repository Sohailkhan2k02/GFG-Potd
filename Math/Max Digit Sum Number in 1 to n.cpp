class Solution {
  public:
    int findMax(int n) {
        // code Here
        int temp = n;
        int sum = 0;
        vector<int>v;
        
        while(temp){
            v.push_back(temp%10);
            sum+=(temp%10);
            temp/=10;
        }
        
        reverse(v.begin(),v.end());
        int pre = 0;
        
        for(int i=1;i<v.size();i++){
            if(v[i]==9)continue;
            else if(pre)v[i]=9;
            else{
                v[i-1]--;
                v[i] = 9;
                pre=1;
            }
        }
        
        
        int n2 = 0;
        int sum2 = 0;
        
        for(int i=0;i<v.size();i++){
            
            sum2+=v[i];
            n2*=10;
            n2+=v[i];
            
        }
        
        
        if(sum2>sum)return n2;
        else return n;
    }
};
