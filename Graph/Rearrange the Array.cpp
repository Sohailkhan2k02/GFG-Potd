using ll=long long;
class Solution {
  public:
    const int md=1e9+7;
    int pw(int a,int b){
        ll mult=a,res=1;
        while(b){
            if(b&1){
                res*=mult;
                res%=md;
            }
            mult*=mult;
            mult%=md;
            b=b>>1;
        }
        return (int)res;
    }
  
    int minOperations(vector<int> &b) {
        // code here
        unordered_map<int,int>mp;
        vector<bool>vis(b.size()+1,false);
        for(int i=1;i<=b.size();i++){
            int count=1;
            if(!vis[i]){
                vis[i]=true;
                int j=b[i-1];
                while(j!=i){
                    count++;
                    vis[j]=true;
                    j=b[j-1];
                }
                int m=sqrt(count);
                int n=count;
                for(int i=2;i<=m;i++){
                    if(n==1) break;
                    if(n%i==0){
                        int ct=0;
                        while(n%i==0){
                            ct++;
                            n/=i;
                        }
                        mp[i]=max(mp[i],ct);
                    }
                }
                if(n!=1){
                    mp[n]=max(mp[n],1);
                }
            }
        }
        int ans=1;
        for(auto[x,y]:mp){
            ans=ans*1LL*pw(x,y)%md;
        }
        return ans;
    }
};
